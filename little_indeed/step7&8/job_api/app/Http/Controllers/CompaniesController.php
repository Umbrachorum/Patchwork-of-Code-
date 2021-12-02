<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Company;
use App\Models\JobApplication;
use App\Models\Job;
use Illuminate\Support\Str;

class CompaniesController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $companies = Company::join('cities', 'cities.id', '=', 'companies.city_id')
		->select('companies.id', 'companies.token_id', 'companies.name', 'companies.description', 'companies.city_id',
		'cities.name AS city_name', 'companies.email', 'companies.premium')
		->get();
        return $companies;
    }

	public function paginatedIndex()
    {
		$companies = Company::join('cities', 'cities.id', '=', 'companies.city_id')
		->select('companies.id', 'companies.token_id', 'companies.name', 'companies.description', 'companies.city_id',
		'cities.name AS city_name', 'companies.email', 'companies.premium')
		->paginate(12);
        return $companies;
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
			'description' => ['required', 'string', 'max:255'],
			'email' => ['required', 'email:rfc'],
			'password' => ['required', 'string'],
			'city_id' => ['required', 'numeric']
		]);

		$company = new Company();
		$company->token_id = Str::random(8);
		$company->name = $validator['name'];
		$company->description = $validator['description'];
		$company->city_id = $validator['city_id'];
		$company->email = $validator['email'];
		$company->password = bcrypt($validator['password']);
		$company->premium = 0;
		$company->isCompany = 1;
		if($company->save())
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
    public function update(Request $request, $token_id)
    {
        $validatedData = $request->validate([
			'name' => ['string', 'max:100', 'nullable'],
			'description' => ['string', 'max:255', 'nullable'],
			'email' => ['email:rfc', 'nullable'],
			'city_id' => ['numeric', 'nullable']
		]);

        $company = Company::where('token_id', $token_id)->firstOrFail();
		$company->name = $this->compare($company->name, $validatedData['name']);
        $company->description = $this->compare($company->description, $validatedData['description']);
        $company->email = $this->compare($company->email, $validatedData['email']);
        $company->city_id = $this->compare($company->city_id, $validatedData['city_id']);
        if($company->update())
        	return ['OK'=>$company];
        return['500: Internal error'];
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($token_id)
    {
        $company = Company::where('token_id', $token_id)->firstOrFail();
		$jobapplications = JobApplication::where('company_id', $company->id)->get();
		$jobs = Job::where('company_id', $company->id)->get();

		if($jobapplications->isNotEmpty()) {
			$jobapplications->each(function ($item, $key) {
				if ($item->delete()) {
				} else {
					return ["500" => "Internal error"];
				}
			});
		}
		if($jobs->isNotEmpty()) {
			$jobs->each(function ($item, $key) {
				if ($item->delete()) {
				} else {
					return ["500" => "Internal error"];
				}
			});
		}

        if($company->delete())
            return ['OK' => 'success'];
        return['500' => 'Internal error'];
    }
}
