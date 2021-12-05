<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\City;
use App\Models\Company;
use App\Models\Job;

class CitiesController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $cities = City::select('id', 'name', 'zipcode')->get();
		return $cities;
    }

	public function paginatedIndex()
    {
		$cities = City::select('id', 'name', 'zipcode')
		->paginate(12);
		return $cities;
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
			'name' => ['required', 'string', 'max:50'],
			'zipcode' => ['required', 'string', 'max:30'],
		]);

        $city = new City();
		$city->name = $validator['name'];
		$city->zipcode = $validator['zipcode'];
		if($city->save())
			return "201: success";
		return['500: Internal error'];
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
    public function update(Request $request, $id)
    {
        $validatedData = $request->validate([
			'name' => ['string', 'max:50', 'nullable'],
			'zipcode' => ['string', 'max:30', 'nullable'],
		]);

        $city = City::where('id', $id)->firstOrFail();
		$city->name = $this->compare($city->name, $validatedData['name']);
		$city->zipcode = $this->compare($city->zipcode, $validatedData['zipcode']);
		if($city->update())
			return ["OK"=>$city];
		return ['500' => 'Internal error'];
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $city = City::where('id', $id)->firstOrFail();
		$companies = Company::where('city_id', $id)->get();
		$jobs = Job::where('city_id', $id)->get();

		if($companies->isNotEmpty() || $jobs->isNotEmpty()) {
			return ["403" => "City deletion forbidden"];
		} else {
			if($city->delete()) {
				return ["OK" => "success"];
			} else {
				return ["500" => "Internal error"];
			}	
		}
    }
}
