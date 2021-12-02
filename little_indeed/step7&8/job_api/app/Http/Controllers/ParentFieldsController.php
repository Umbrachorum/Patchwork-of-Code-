<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\ParentField;
use App\Models\ChildField;

class ParentFieldsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $parents = ParentField::select('id', 'name')->get();
		return $parents;
    }

	public function paginatedIndex()
    {
        $parents = ParentField::select('id', 'name')
		->paginate(12);
		return $parents;
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
			'name' => ['required', 'string', 'max:50']
		]);

        $parent = new ParentField();
		$parent->name = $validator['name'];
		if($parent->save())
			return ["OK" => "201: success"];
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
			'name' => ['string', 'max:50', 'nullable']
		]);

		$parent = ParentField::where('id', $id)->firstOrFail();
		$parent->name = $this->compare($parent->name, $validatedData['name']);
        if($parent->update())
        	return ['OK'=>$parent];
        return['500: Internal error'];
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $parent = ParentField::where('id', $id)->firstOrFail();
		$child_fields = ChildField::where('parent_fields_id', $parent->id)->get();

		if($child_fields->isNotEmpty()) {
			$child_fields->each(function ($item, $key) {
				if ($item->delete()) {
				} else {
					return "500: Internal error";
				}
			});
		}

        if($parent->delete())
            return ['200: success'];
        return['500: Internal error'];
    }
}
