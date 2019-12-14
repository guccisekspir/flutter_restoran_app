<?php

namespace App\Http\Controllers;

use App\Product;
use App\Restaurant;
use Illuminate\Http\Request;
use Illuminate\Validation\ValidationException;
use Illuminate\Validation\Validator;

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

        $order = $restaurant->order()->create([
            'product_id' => $request->product_id,
            'table_id' => $request->table_id,
            'amount' => $request->amount
        ]);

        $table->update([
            'is_full' => true,
            'amount' => $table->getTotalPrice()
        ]);

        return response()->json($order);
    }

    public function createOrderWithJSONRequest($id, Request $request)
    {
        // TODO: get json request with POST and parse it, then foreach loop and adding each product
        $restaurant = Restaurant::findOrFail($id);

        $jsonRequest = json_decode($request->json, true);
        $rules = [
            'product_id' => 'exists:products|numeric',
            'table_id' => 'exists:tables|numeric',
            'amount' => 'numeric'
        ];

        $validator = Validator::make($jsonRequest, $rules);
        if (!$validator->passes()) {
            return response()->json(['state' => 'unsuccessful']);
        }

        foreach ($jsonRequest as $order)
        {
            $newOrder = $restaurant->order()->create([
                'product_id' => $order->product_id,
                'table_id' => $order->table_id,
                'amount' => $order->amount
            ]);

            $restaurant->table()->update([

            ]);
        }



        return response()->json(['state' => 'orders taken']);
    }
    // TODO: Test table close, add new order functions etc.
}
