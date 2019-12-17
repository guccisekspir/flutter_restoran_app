<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Restaurant extends Model
{
    protected $fillable = [
        'name'
    ];

    protected $hidden = [
        'api_token'
    ];

    public function table()
    {
        return $this->hasMany(Table::class);
    }

    public function product()
    {
        return $this->hasMany(Product::class);
    }

    public function order()
    {
        return $this->hasMany(Order::class);
    }
}
