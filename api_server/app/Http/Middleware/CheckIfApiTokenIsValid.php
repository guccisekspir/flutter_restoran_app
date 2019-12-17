<?php

namespace App\Http\Middleware;

use App\Restaurant;
use Closure;

class CheckIfApiTokenIsValid
{
    /**
     * Handle an incoming request.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \Closure  $next
     * @return mixed
     */
    public function handle($request, Closure $next)
    {
        $restaurant = Restaurant::findOrFail($request->route('id'));
        if ($restaurant->api_token == $request->api_token) {
            return $next($request);
        }
        return response()->json(['state' => 'auth failed']);
    }
}
