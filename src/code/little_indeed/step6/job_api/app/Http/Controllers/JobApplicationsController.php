<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\JobApplication;
use Illuminate\Support\Str;

class JobApplicationsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $jobapps = JobApplication::join('jobs', 'jobs.id', '=', 'job_applications.job_id')
		->join('companies', 'companies.id', '=', 'job_applications.company_id')
		->join('cities', 'cities.id', '=', 'jobs.city_id')
		->select(
			'job_applications.token_id', 'job_applications.message', 'job_applications.cv', 'job_applications.motivation_letter',
			'jobs.title AS job_title', 'jobs.description AS job_description', 'jobs.worktime AS job_worktime', 'jobs.salary AS job_salary', 
			'companies.name AS company_name', 'companies.email AS company_email',
			'job_applications.email AS user_email', 'job_applications.lastname AS user_lastname', 'job_applications.firstname AS user_firstname','job_applications.phone_number AS user_phone_number',
			'cities.name AS city_name'
		)
		->get();

		return $jobapps;
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
			'message' => ['required', 'string', 'max:255'],
			'firstname' => ['required', 'string', 'max:50'],
			'lastname' => ['required', 'string', 'max:50'],
			'email' => ['required', 'email:rfc'],
			'phone_number' => ['required', 'numeric'],
			'cv' => ['nullable'],
			'motivation_letter' => ['nullable'],
			'job_id' => ['required', 'numeric'],
			'company_id' => ['required', 'numeric']
		]);

        $job = new JobApplication();
		$job->token_id = Str::random(12);
		$job->message = $validator['message'];
		$job->firstname = $validator['firstname'];
		$job->lastname = $validator['lastname'];
		$job->phone_number = $validator['phone_number'];
		$job->email = $validator['email'];
		$job->job_id = $validator['job_id'];
		$job->company_id = $validator['company_id'];
		$job->cv = $validator['cv'];
		$job->motivation_letter = $validator['motivation_letter'];
		if($job->save()) {
			return ["OK" => "201: success"];
		} else {
			return ["500" => "Internal error"];
		}
    }

	private function compare($str1, $str2) {
		if($str1 !== $str2 && $str2 !== null) {
			return $str2;
		} else {
			return $str1;
		}
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
			'message' => ['string', 'max:255', 'nullable'],
			'firstname' => ['string', 'max:50', 'nullable'],
			'lastname' => ['string', 'max:50', 'nullable'],
			'email' => ['email:rfc', 'nullable'],
			'phone_number' => ['numeric', 'nullable'],
			'job_id' => ['numeric', 'nullable'],
			'company_id' => ['numeric', 'nullable'],
			'cv' => ['nullable'],
			'motivation_letter' => ['nullable']
		]);

		$jobapp = JobApplication::where('token_id', $token_id)->firstOrFail();
		$jobapp->message = $this->compare($jobapp->message, $validatedData['message']);
		$jobapp->firstname = $this->compare($jobapp->firstname, $validatedData['firstname']);
		$jobapp->lastname = $this->compare($jobapp->lastname, $validatedData['lastname']);
		$jobapp->email = $this->compare($jobapp->email, $validatedData['email']);
		$jobapp->phone_number = $this->compare($jobapp->phone_number, $validatedData['phone_number']);
        $jobapp->job_id = $this->compare($jobapp->job_id, $validatedData['job_id']);
		$jobapp->company_id = $this->compare($jobapp->company_id, $validatedData["company_id"]);
        $jobapp->cv = $this->compare($jobapp->cv, $validatedData['cv']);
        $jobapp->motivation_letter = $this->compare($jobapp->motivation_letter, $validatedData['motivation_letter']);
        if($jobapp->update())
        	return ['201: success'=>$jobapp];
        return['500' => 'Internal error'];		
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($token_id)
    {
        $jobapp = JobApplication::where('token_id', $token_id)->firstOrFail();
		if($jobapp->delete())
			return["200" => "success"];
		return["500" => "Internal error"];
    }

	public function getJobApplication($id) {

		$jobapps = JobApplication::join('jobs', 'jobs.id', '=', 'job_applications.job_id')
		->join('companies', 'companies.id', '=', 'job_applications.company_id')
		->join('cities', 'cities.id', '=', 'jobs.city_id')
		->select(
			'job_applications.token_id', 'job_applications.message', 'job_applications.cv', 'job_applications.motivation_letter',
			'jobs.title AS job_title', 'jobs.description AS job_description', 'jobs.worktime AS job_worktime', 'jobs.salary AS job_salary', 
			'companies.name AS company_name', 'companies.email AS company_email',
			'job_applications.email AS user_email', 'job_applications.lastname AS user_lastname', 'job_applications.firstname AS user_firstname','job_applications.phone_number AS user_phone_number',
			'cities.name AS city_name'
		)
		->where('companies.id', $id)
		->get();
		return $jobapps;
	}
}