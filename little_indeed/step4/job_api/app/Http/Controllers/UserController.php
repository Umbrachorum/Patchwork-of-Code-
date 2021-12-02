<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Str;
use App\Models\User;
use App\Models\JobApplication;
use App\Models\Document;

class UsersController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {

        $users = User::select('id', 'token_id', 'firstname', 'lastname', 'phone_number', 'email', 'birthdate', 'premium', 'isAdmin')
						->get();
        return $users;
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create(Request $request)
    {
        $item = new User;
        $item->name = $request->name;
        $item->lastname = $request->lastname;
        $item->firstname = $request->firstname;
        $item->username = $request->username;
        $item->phone_number = $request->phone_number;
        $item->birthdate = $request->birthdate;
        $item->email = $request->email;
        $item->password = $request->password;
        $item->premium = 1;
        $item->isAdmin = 1;
        $item->save();

        if ($item->save())
            return ['success' => $item];
        return ['success' => 'fail'];
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {	
		$validator = $request->validate([
			'firstname' => ['required', 'string', 'max:50'],
			'lastname' => ['required', 'string', 'max:50'],
			'birthdate' => ['required', 'date'],
			'phone_number' => ['required', 'string', 'max:20'],
			'email' => ['required', 'email:rfc'],
			'password' => ['required', 'string'],
		]);

        $user = new User();
        $user->firstname = $validator['firstname'];
        $user->lastname = $validator['lastname'];
		$user->token_id = Str::random(8);
		$user->birthdate = $validator['birthdate'];
		$user->email = $validator['email'];
		$user->phone_number = $validator['phone_number'];
		$user->password = bcrypt($validator['password']);
		$user->premium = 0;
		$user->isAdmin = 0;
		$user->isCompany = 0;
		if($user->save()) {
			return "201: Success";
		} else {
			return "500: Internal error";
		}
    }

	private function compare($str_1, $str_2)
    {
        if($str_1 !== $str_2 && $str_2 !== null)
            return $str_2;
        else
            return $str_1;
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $token_id)
    {
        $validatedData = $request->validate([
			'firstname' => ['string', 'max:50', 'nullable'],
			'lastname' => ['string', 'max:50', 'nullable'],
			'birthdate' => ['date', 'nullable'],
			'phone_number' => ['string', 'max:20', 'nullable'],
			'email' => ['email:rfc', 'nullable']
		]);

        $user = User::where('token_id', $token_id)->firstOrFail();
		$user->firstname = $this->compare($user->firstname, $validatedData['firstname']);
        $user->lastname = $this->compare($user->lastname, $validatedData['lastname']);
        $user->birthdate = $this->compare($user->birthdate, $validatedData['birthdate']);
        $user->phone_number = $this->compare($user->phone_number, $validatedData['phone_number']);
        $user->email = $this->compare($user->email, $validatedData['email']);
        if($user->update())
        	return ['200: success'=>$user];
        return['500' => 'Internal error'];
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $user = User::where('id', $id)->firstOrFail();
		$documents = Document::where('user_id', $id)->get();

		if($documents->isNotEmpty()) {
			$documents->each(function ($item, $key) {
				if ($item->delete()) {
				} else {
					return ["500" => "Internal error"];
				}
			});
		}

        if($user->delete())
            return ['200' => 'success'];
        return['500' => 'Internal error'];
    }
}
