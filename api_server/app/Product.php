<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Product extends Model
{
    protected $fillable = [
        'name',
        'price',
        'thumbnail'
    ];

    public function restaurant()
    {
        return $this->belongsTo(Restaurant::class);
    }
}
