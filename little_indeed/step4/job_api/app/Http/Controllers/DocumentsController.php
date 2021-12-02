<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Document;

class DocumentsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $documents = Document::join("users", "users.id", "=", "documents.user_id")
		->select("documents.id", "users.firstname AS user_firstname", "users.lastname AS user_lastname", "users.email AS user_email", "users.premium AS user_premium",
		"documents.cv", "documents.motivation_letter")
		->get();

		return $documents;
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
			'user_id' => ['required', 'numeric'],
			'cv' => ['nullable'],
			'motivation_letter' => ['nullable']
		]);
		
		$document = new Company();
		$document->user_id = $validator['user_id'];
		if($document->save())
			return ["201" => "success"];
		return['500' => 'Internal error'];
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
    public function update(Request $request, $id)
    {
        $validatedData = $request->validate([
			'user_id' => ['numeric', 'nullable'],
			'cv' => ['nullable'],
			'motivation_letter' => ['nullable']
		]);

		$document = Document::where("id", $id)->firstOrFail();
		$document->user_id = $this->compare($document->user_id, $validatedData['user_id']);
		$document->cv = $this->compare($document->cv, $validatedData['cv']);
		$document->motivation_letter = $this->compare($document->motivation_letter, $validatedData['motivation_letter']);
		if($document->update())
			return['201: success' => $document];
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
		$document = Document::where("id", $id)->firstOrFail();
		if($document->delete())
			return['200' => 'success'];
		return['500' => 'Internal error'];
    }
}
