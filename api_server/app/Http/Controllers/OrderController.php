<?php

namespace App\Http\Controllers;

use App\Product;
use App\Restaurant;
use Illuminate\Http\Request;
use Illuminate\Validation\ValidationException;

class OrderController extends Controller
{
    public function index($id)
    {
        $restaurant = Restaurant::findOrFail($id);
        $orders = $restaurant->order()->get();

        return response()->json($orders);
    }

    public function show($id, $orderId)
    {
        $restaurant = Restaurant::findOrFail($id);
        $order = $restaurant->order()->find($orderId)->get();

        return response()->json($order);
    }

    public function calculatePrice($productId, $amount)
    {
        $price = Product::where('id', $productId)->first()->price;
        return $amount * $price;
    }

    public function createOrder($id, Request $request)
    {
        try {
            $this->validate($request, [
                'product_id' => 'exists:products|numeric',
                'table_id' => 'exists:tables|numeric',
                'amount' => 'numeric'
            ]);
        } catch (ValidationException $e) {
            return response()->json(['state' => 'unsuccessful']);
        }

        $restaurant = Restaurant::findOrFail($id);
        $table = $restaurant->table()->findOrFail($request->table_id);

        $tempAmount = $table->amount;

        $table->update([
            'is_full' => true,
            'amount' => $tempAmount + $this->calculatePrice($request->product_id, $request->amount)
        ]);

        $order = $restaurant->order()->create([
            'product_id' => $request->product_id,
            'table_id' => $request->table_id,
            'amount' => $request->amount
        ]);

        return response()->json($order);
    }

    public function createOrderWithJSONRequest($id, Request $request)
    {
        // TODO: get json request with POST and parse it, then foreach loop and adding each product
    }
    // TODO: Test table close, add new order functions etc.
}
