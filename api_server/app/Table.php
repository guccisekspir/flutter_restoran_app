<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Table extends Model
{
    protected $fillable = [
        'name',
        'restaurant_id',
        'amount',
        'is_full'
    ];

    public function restaurant()
    {
        return $this->belongsTo(Restaurant::class);
    }

    public function order()
    {
        return $this->hasMany(Order::class);
    }

    public function getTotalPrice()
    {
        $orders = Order::where('table_id', $this->id)->get();

        $totalPrice = 0;
        foreach ($orders as $order)
        {
            $totalPrice += $order->amount * $order->product()->get()->first()->price;
        }

        return $totalPrice;
    }
}
