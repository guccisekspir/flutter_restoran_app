<?php

namespace App\Http\Controllers;

use App\Product;
use App\Restaurant;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Validator;
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

    public function createOrder($id, Request $request)
    {
        try {
            $this->validate($request, [
                'product_id' => 'required|exists:products,id',
                'table_id' => 'required|exists:tables,id',
                'amount' => 'required|numeric'
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
        $restaurant = Restaurant::findOrFail($id);

        $jsonRequest = json_decode($request->json);
        $rules = [
            'product_id' => 'required|exists:products,id',
            'table_id' => 'required|exists:tables,id',
            'amount' => 'required|numeric'
        ];

        foreach ($jsonRequest as $order) {
            $validator = Validator::make((array) $order, $rules);
            if (!$validator->passes()) {
                return response()->json(['state' => 'unsuccessful']);
            }

            $newOrder = $restaurant->order()->create([
                'product_id' => $order->product_id,
                'table_id' => $order->table_id,
                'amount' => $order->amount
            ]);

            $restaurant->table()->where('id', $order->table_id)->update([
                'is_full' => true,
                'amount' => $restaurant->table()->where('id', $order->table_id)->get()->first()->getTotalPrice()
            ]);
        }

        return response()->json(['state' => 'orders taken']);
    }
}
