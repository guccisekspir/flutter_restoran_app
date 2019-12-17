<?php

namespace App\Http\Controllers;

use App\Restaurant;
use Illuminate\Http\Request;

class KitchenController extends Controller
{
    public function index($id)
    {
        $restaurant = Restaurant::findOrFail($id);

        $orders = $restaurant->order()->orderBy('created_at', 'DESC')->get();
        return response()->json($orders);
    }

    public function completeOrder($id, $orderId)
    {
        $restaurant = Restaurant::findOrFail($id);

        $order = $restaurant->order()->where('id', $orderId)->get();
        $order->update([
            'state' => true
        ]);

        return response()->json($order);
    }
}
