<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Restaurant extends Model
{
    public $timestamps = false;

    protected $fillable = ['name'];
}
