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
        'email' => 'required|email:rfc|unique:users,email',
        'password' => 'required|string|confirmed',
        'birthdate' => 'required|string',
        'phone_number' => 'required|string'
        ]);
        $user = User::create([
            'lastname' => $fields['lastname'],
            'firstname' => $fields['firstname'],
            'email' => $fields['email'],
            'password' => bcrypt($fields['password']),
            'token_id' => Str::random(12),
            'birthdate' => $fields['birthdate'],
            'phone_number' => $fields['phone_number'],
            'premium' => 0,
            'isAdmin' => 0,
            'isCompany' => 0
        ]);
        $token = $user->createToken('myapptoken')->plainTextToken;
        $response = [
            'user' => $user,
            'token' => $token
        ];
        return response($response, 201);
    }

	public function registerAdmin(Request $request) {
        $fields = $request->validate([
        'lastname' => 'required|string',
        'firstname' => 'required|string',
        'email' => 'required|email:rfc|unique:users,email',
        'password' => 'required|string|confirmed',
        'birthdate' => 'required|string',
        'phone_number' => 'required|string'
        ]);
        $user = User::create([
            'lastname' => $fields['lastname'],
            'firstname' => $fields['firstname'],
            'email' => $fields['email'],
            'password' => bcrypt($fields['password']),
            'token_id' => Str::random(12),
            'birthdate' => $fields['birthdate'],
            'phone_number' => $fields['phone_number'],
            'premium' => 0,
            'isAdmin' => 0,
            'isCompany' => 0
        ]);
        return response(201);
    }

    public function login(Request $request) {
        $fields = $request->validate([
			'email' => 'required|email:rfc',
			'password' => 'required|string'
        ]);
        $user = User::where('email', $fields['email'])->first();
        if(!$user || !Hash::check($fields['password'], $user->password)) {
            return response([ 'message' => 'Wrong identification' ], 401);
        }
        $token = $user->createToken('myapptoken')->plainTextToken;
        $response = [
            'user' => $user,
            'token' => $token
        ];
        return response($response, 201);
    }

	public function changePassword(Request $request, $id) {
		$fields = $request->validate([
			'actual_password' => 'required|string',
			'password' => 'required|string',
			'password_confirmation' => 'required|string'
		]);
		$user = User::where('id', $id)->first();
		if(Hash::check($fields['actual_password'], $user->password)) {
			$user->password = bcrypt($fields['password']);
			if($user->update())
				return ['OK'=>'200: success'];
		} else {
			return ["Unauthorized"=>"401"];
		}
		
	}

	public function changePasswordAdmin(Request $request, $token_id) {
		$fields = $request->validate([
			'password' => 'required|string',
			'password_confirmation' => 'required|string'
		]);
		$user = User::where('token_id', $token_id)->first();
		$user->password = bcrypt($fields['password']);
		if($user->update())
			return ['OK'=>'200: success'];
	}

    public function logout(Request $request)
    {
        auth('sanctum')->user()->tokens()->delete();
        return [
            'message' => 'Logged out'
        ];
    }
}
