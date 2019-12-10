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

        $table = $restaurant->table()->create([
            'name' => $request->name
        ]);

        return response()->json($table);
    }

    public function show($id, $tableId)
    {
        $restaurant = Restaurant::findOrFail($id);
        $table = $restaurant->table()->where('id', $tableId)->first();

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
        $table = $restaurant->table()->where('id', $tableId);

        $table->update([
            'name' => $request->name
        ]);

        return response()->json($table->first());
    }

    public function close($id, $tableId)
    {
        $restaurant = Restaurant::findOrFail($id);
        $table = $restaurant->table()->findOrFail($tableId);

        $table->update([
            'is_full' => false,
            'amount' => 0
        ]);

        $orderIds = $table->order()->pluck(['id']);

        DB::table('orders')->whereIn('id', $orderIds)->delete();

        return response()->json($table);
    }
}
