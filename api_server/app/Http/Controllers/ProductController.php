<?php

namespace App\Http\Controllers;

use App\Restaurant;
use Illuminate\Http\Request;
use Illuminate\Validation\ValidationException;

class ProductController extends Controller
{
    public function index($id)
    {
        $restaurant = Restaurant::findOrFail($id);
        $products = $restaurant->product()->get();

        return response()->json($products);
    }

    public function store(Request $request, $id)
    {
        try {
            $this->validate($request, [
                'name' => 'required|max:40',
                'price' => 'numeric'
            ]);
        } catch (ValidationException $e) {
            return response()->json(['state' => 'unsuccessful']);
        }

        $restaurant = Restaurant::findOrFail($id);

        $product = $restaurant->product()->create([
            'name' => $request->name,
            'price' => $request->price,
            'thumbnail' => $request->thumbnail
        ]);

        return response()->json($product);
    }

    public function show($id, $productId)
    {
        $restaurant = Restaurant::findOrFail($id);
        $product = $restaurant->product()->where('id', $productId)->first();

        return response()->json($product);
    }

    public function edit(Request $request, $id, $productId)
    {
        try {
            $this->validate($request, [
                'name' => 'required|max:40',
                'price' => 'numeric'
            ]);
        } catch (ValidationException $e) {
            return response()->json(['state' => 'unsuccessful']);
        }

        $restaurant = Restaurant::findOrFail($id);
        $product = $restaurant->product()->where('id', $productId);

        $product->update([
            'name' => $request->name,
            'price' => $request->price
        ]);

        return response()->json($product->first());
    }
}
