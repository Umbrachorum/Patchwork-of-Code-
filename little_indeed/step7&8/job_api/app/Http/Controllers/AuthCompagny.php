<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Company;
use Illuminate\Http\Response;
use Illuminate\Support\Str;
use Illuminate\Support\Facades\Hash;

class AuthCompagny extends Controller
{
	public function register(Request $request) {
		$fields = $request->validate([
			'description' => 'required|string',
			'name' => 'required|string',
			'email' => 'required|string|unique:companies,email',
			'password' => 'required|string|confirmed',
			'city_id' => 'required|numeric'
		]);
		$company = Company::create([
			'description' => $fields['description'],
			'name' => $fields['name'],
			'email' => $fields['email'],
			'password' => bcrypt($fields['password']),
			'token_id' => Str::random(12),
			'city_id' => $fields['city_id'],
			'premium' => 0,
			'isCompany' => 1
		]);
		$token = $company->createToken('myapptoken')->plainTextToken;
		$response = [
			'companies' => $company,
			'token' => $token
		];
		return response($response, 201);
	}

	public function registerAdmin(Request $request) {
		$fields = $request->validate([
			'description' => 'required|string',
			'name' => 'required|string',
			'email' => 'required|string|unique:companies,email',
			'password' => 'required|string|confirmed',
			'city_id' => 'required|numeric'
		]);
		$company = Company::create([
			'description' => $fields['description'],
			'name' => $fields['name'],
			'email' => $fields['email'],
			'password' => bcrypt($fields['password']),
			'token_id' => Str::random(12),
			'city_id' => $fields['city_id'],
			'premium' => 0,
			'isCompany' => 1
		]);
		return response(201);
	}

	public function changePassword(Request $request, $id) {
		$fields = $request->validate([
			'actual_password' => 'required|string',
			'password' => 'required|string',
			'password_confirmation' => 'required|string'
		]);
		$company = Company::where('id', $id)->first();
		if(!$company || !Hash::check($fields['actual_password'], $company->password)) {
			$company->password = bcrypt($fields['password']);
			$company->save();
		}
		return ['OK'=>'200: success'];
	}

	public function changePasswordAdmin(Request $request) {
		$fields = $request->validate([
			'token_id' => 'required|string',
			'password' => 'required|string',
			'password_confirmation' => 'required|string'
		]);
		$company = Company::where('token_id', $fields['email'])->first();
		$company->password = bcrypt($fields['password']);
		$company->save();
		
		return ['OK'=>'200: success'];
	}

	public function login(Request $request) {
		$fields = $request->validate([
				'email' => 'required|string',
				'password' => 'required|string'
			]);
		$company = Company::where('email', $fields['email'])->first();
		if(!$company || !Hash::check($fields['password'], $company->password)) {
			return response([ 'message' => 'err' ], 401);
		}
		$token = $company->createToken('myapptoken')->plainTextToken;
		$response = [
			'companies' => $company,
			'token' => $token
		];
		return response($response, 201);
	}
	public function logout(Request $request) {
			auth('sanctum')->user()->tokens()->delete();
			return [
				'message' => 'Logged out'
			];
	}
}