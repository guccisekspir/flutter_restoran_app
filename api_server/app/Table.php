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
}
