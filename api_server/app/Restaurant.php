<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Restaurant extends Model
{
    protected $fillable = [
      'name'
    ];

    public function table()
    {
        return $this->hasMany(Table::class);
    }
}
