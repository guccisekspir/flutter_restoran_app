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
Route::get('/restaurants', 'RestaurantController@index');
Route::post('/restaurants', 'RestaurantController@store');
Route::get('/restaurant/{id}', 'RestaurantController@show');
Route::post('/restaurant/{id}', 'RestaurantController@edit');

// table routes
Route::get('/restaurant/{id}/tables', 'TableController@index');
Route::post('/restaurant/{id}/tables', 'TableController@store');
Route::get('/restaurant/{id}/table/{tableId}', 'TableController@show');
Route::post('/restaurant/{id}/table/{tableId}', 'TableController@edit');
Route::get('/restaurant/{id}/table/{tableId}/close', 'TableController@close');

// product routes
Route::get('/restaurant/{id}/products', 'ProductController@index');
Route::post('/restaurant/{id}/products', 'ProductController@store');
Route::get('/restaurant/{id}/product/{productId}', 'ProductController@show');
Route::post('/restaurant/{id}/product/{productId}', 'ProductController@edit');

// order routes
Route::get('/restaurant/{id}/orders', 'OrderController@index');
Route::get('/restaurant/{id}/order/{orderId}', 'OrderController@show');
Route::post('/restaurant/{id}/orders/create', 'OrderController@createOrder');
Route::post('/restaurant/{id}/orders/json', 'OrderController@createOrderWithJSONRequest');
