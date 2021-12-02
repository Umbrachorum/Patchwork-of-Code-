<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;
use App\Models\Job;
use App\Models\JobApplication;
use Illuminate\Support\Str;
use DateTime;

class JobsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {

        $result = Job::select('jobs.token_id', 'jobs.company_id', 'jobs.id', 'jobs.title', 'jobs.description', 'jobs.worktime', 'jobs.salary', 'cities.name AS city_name', 'parent_fields.name AS parent_field_name', 'child_fields.name AS child_field_name', 'companies.name AS company_name')
		->join('parent_fields', 'parent_fields.id', '=', 'jobs.parent_fields_id')
		->join('child_fields', 'child_fields.id', '=', 'jobs.child_fields_id')
		->join('cities', 'cities.id', '=', 'jobs.city_id')
		->join('companies', 'companies.id', '=', 'jobs.company_id')
		->orderBy('id', 'asc')
		->get();

        // "SELECT j.token_id, j.title, j.description, j.worktime, j.salary, ct.name AS city_name, p.name AS parent_field_name, cf.name AS child_field_name, cp.name AS company_name
        // FROM jobs j
        // INNER JOIN parent_fields p ON j.parent_fields_id = p.id
        // INNER JOIN child_fields cf ON j.child_fields_id = cf.id
        // INNER JOIN cities ct ON j.city_id = ct.id
        // INNER JOIN companies cp ON j.company_id = cp.id"

        return $result;
    }

    private function compare($str_1, $str_2)
    {
        if ($str_1 !== $str_2 && $str_2 !== null)
            return $str_2;
        else
            return $str_1;
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
            'title' => ['required', 'string', 'max:100'],
            'description' => ['required', 'string', 'max:255'],
            'salary' => ['required', 'numeric'],
            'worktime' => ['required', 'numeric'],
            'city_id' => ['required', 'numeric'],
            'parent_fields_id' => ['required', 'numeric'],
            'child_fields_id' => ['required', 'numeric'],
            'company_id' => ['required', 'numeric']
        ]);


        $job = new Job();
        $job->token_id = Str::random(12);
        $job->title = $validator["title"];
        $job->description = $validator["description"];
        $job->salary = $validator["salary"];
        $job->worktime = $validator["worktime"];
        $job->city_id = $validator["city_id"];
        $job->parent_fields_id = $validator["parent_fields_id"];
        $job->child_fields_id = $validator["child_fields_id"];
        $job->company_id = $validator["company_id"];
        if ($job->save())
            return "201: success";
        return ['500' => 'Internal error'];
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
            'title' => ['string', 'max:100', 'nullable'],
            'description' => ['string', 'max:255', 'nullable'],
            'salary' => ['numeric', 'nullable'],
            'worktime' => ['numeric', 'nullable'],
            'city_id' => ['numeric', 'nullable'],
            'parent_fields_id' => ['numeric', 'nullable'],
            'child_fields_id' => ['numeric', 'nullable'],
            'company_id' => ['numeric', 'nullable']
        ]);

        $item = Job::where('id', $id)->firstOrFail();
        $item->title = $this->compare($item->title, $validatedData['title']);
        $item->description = $this->compare($item->description, $validatedData['description']);
        $item->salary = $this->compare($item->salary, $validatedData['salary']);
        $item->worktime = $this->compare($item->worktime, $validatedData['worktime']);
        $item->city_id = $this->compare($item->city_id, $validatedData['city_id']);
        $item->company_id = $this->compare($item->company_id, $validatedData["company_id"]);
        $item->parent_fields_id = $this->compare($item->parent_fields_id, $validatedData['parent_fields_id']);
        $item->child_fields_id = $this->compare($item->child_fields_id, $validatedData['child_fields_id']);
        if ($item->update())
            return ['200: success' => $item];
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
        $jobs = Job::where('id', $id)->firstOrFail();
        $jobapplications = JobApplication::where('job_id', $jobs->id)->get();

        if ($jobapplications->isNotEmpty()) {
            $jobapplications->each(function ($item, $key) {
                if ($item->delete()) {
                } else {
                    return "500: Internal error";
                }
            });
        }
        if ($jobs->delete())
            return ['200: success'];
        return ['500' => 'Internal error'];
    }

	public function getJob($id) {

		$job = Job::select('jobs.token_id', 'jobs.company_id', 'jobs.id', 'jobs.title', 'jobs.description', 'jobs.worktime', 'jobs.salary', 'cities.name AS city_name', 'parent_fields.name AS parent_field_name', 'child_fields.name AS child_field_name', 'companies.name AS company_name')
		->join('parent_fields', 'parent_fields.id', '=', 'jobs.parent_fields_id')
		->join('child_fields', 'child_fields.id', '=', 'jobs.child_fields_id')
		->join('cities', 'cities.id', '=', 'jobs.city_id')
		->join('companies', 'companies.id', '=', 'jobs.company_id')
		->where('jobs.id', $id)
		->firstOrFail();

		return $job;

	}
}
