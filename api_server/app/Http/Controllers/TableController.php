<?php

namespace App\Http\Controllers;

use App\Restaurant;
use App\Table;
use Illuminate\Http\Request;
use Illuminate\Validation\ValidationException;

class TableController extends Controller
{
    // TODO: 404ler response döndürecek

    public function index($id)
    {
        $restaurant = Restaurant::findOrFail($id);
        $tables = $restaurant->table()->get();

        return response()->json($tables);
    }

    public function store(Request $request, $id)
    {
        try {
            $this->validate($request, [
                'name' => 'required|max:40',
            ]);
        } catch (ValidationException $e) {
            return response()->json(['state' => 'unsuccessful']);
        }

        $restaurant = Restaurant::findOrFail($id);

        $table = Table::create([
            'name' => $request->name,
            'restaurant_id' => $id
        ]);

        return response()->json($table);
    }

    public function edit(Request $request, $id, $tableId)
    {
        try {
            $this->validate($request, [
                'name' => 'required|max:40',
            ]);
        } catch (ValidationException $e) {
            return response()->json(['state' => 'unsuccessful']);
        }

        $restaurant = Restaurant::findOrFail($id);

        $table = Table::findOrFail($tableId);

        $table->update([
            'name' => $request->name
        ]);

        return response()->json($table);
    }
}
