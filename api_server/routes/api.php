<?php

use Illuminate\Http\Request;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::get('/', function() {
    return response()->json('api server online. token: ' . Hash::make(time()));
});

// restaurant routes
Route::get('/restaurant', 'RestaurantController@index');
Route::post('/restaurant', 'RestaurantController@store');
Route::get('/restaurant/{id}', 'RestaurantController@show');
Route::post('/restaurant/{id}', 'RestaurantController@edit');

// table routes
Route::get('/restaurant/{id}/table', 'TableController@index');
Route::post('/restaurant/{id}/table', 'TableController@store');
Route::post('/restaurant/{id}/table/{tableId}', 'TableController@edit');
