<?php

namespace App\Http\Controllers;

use App\Models\User;
use Illuminate\Http\Request;
use Illuminate\Http\Response;
use Illuminate\Support\Str;
use Illuminate\Support\Facades\Hash;

class AuthController extends Controller
{
    public function register(Request $request) {
        $fields = $request->validate([
        'lastname' => 'required|string',
        'firstname' => 'required|string',
        'email' => 'required|string|unique:users,email',
        'password' => 'required|string|confirmed',
        'birthdate' => 'required|string',
        'phone_number' => 'required|string'
        ]);
        $user = User::create([
            'lastname' => $fields['lastname'],
            'firstname' => $fields['firstname'],
            'email' => $fields['email'],
            'password' => bcrypt($fields['password']),
            'token_id' => Str::random(8),
            'birthdate' => $fields['birthdate'],
            'phone_number' => $fields['phone_number'],
            'premium' => 0,
            'isAdmin' => 0,
            'isCompany' => 0
        ]);
        $token = $user->createToken('myapptoken')->plainTextToken;
        $response = [
            'users' => $user,
            'token' => $token
        ];
        return response($response, 201);
    }

    public function

    public function login(Request $request) {
        $fields = $request->validate([
        'email' => 'required|string',
        'password' => 'required|string'
        ]);
        $user = User::where('email', $fields['email'])->first();
        if(!$user || !Hash::check($fields['password'], $user->password)) {
            return response([ 'message' => 'err' ], 401);
        }
        $token = $user->createToken('myapptoken')->plainTextToken;
        $response = [
            'user' => $user,
            'token' => $token
        ];
        return response($response, 201);
    }

    public function logout(Request $request)
    {
        auth('sanctum')->user()->tokens()->delete();
        return [
            'message' => 'Logged out'
        ];
    }
}
