<?php

namespace App\Http\Controllers;

use App\Restaurant;
use Illuminate\Http\Request;
use Illuminate\Validation\ValidationException;

class RestaurantController extends Controller
{
    public function index()
    {
        $restaurants = Restaurant::all();

        return response()->json($restaurants);
    }

    public function show($id)
    {
        $restaurant = Restaurant::findOrFail($id);

        return response()->json($restaurant);
    }

    public function store(Request $request)
    {
        try {
            $this->validate($request, [
                'name' => 'required|max:40'
            ]);
        } catch (ValidationException $e) {
            return response()->json(['state' => 'unsuccessful']);
        }

        $restaurant = Restaurant::create([
            'name' => $request->name
        ]);

        return response()->json($restaurant);
    }

    public function edit(Request $request, $id)
    {
        try {
            $this->validate($request, [
                'name' => 'required|max:40'
            ]);
        } catch (ValidationException $e) {
            return response()->json(['state' => 'unsuccessful']);
        }

        $restaurant = Restaurant::findOrFail($id);

        $restaurant->update([
            'name' => $request->name
        ]);

        return response()->json($restaurant);
    }
}
