<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\ChildField;

class ChildFieldsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
		$childs = ChildField::select('child_fields.id', 'child_fields.name', 'parent_fields.name AS parent_name', 'child_fields.parent_fields_id')
		->join('parent_fields', 'parent_fields.id', '=', 'child_fields.id')
		->get();
		return $childs;
    }

	public function paginatedIndex()
    {
        $childs = ChildField::select('child_fields.id', 'child_fields.name', 'parent_fields.name AS parent_name', 'child_fields.parent_fields_id')
		->join('parent_fields', 'parent_fields.id', '=', 'child_fields.id')
		->paginate(12);
		return $childs;
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
			'parent_fields_id' => ['required', 'numeric'],
		]);

		$child = new ChildField();
		$child->name = $validator['name'];
		$child->parent_fields_id = $validator['parent_fields_id'];
		if($child->save())
			return ["201" => "success"];
		return["500" => "Internal error"];
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
			'parent_fields_id' => ['numeric', 'nullable'],
		]);

        $child = ChildField::where('id', $id)->firstOrFail();
		$child->name = $this->compare($child->name, $validatedData['name']);
        $child->parent_fields_id = $this->compare($child->parent_fields_id, $validatedData['parent_fields_id']);
        if($child->update())
        	return ['OK'=>$child];
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
		$child = ChildField::where('id', $id)->firstOrFail();
        if($child->delete())
            return ['OK' => 'success'];
        return['500' => 'Internal error'];
    }
}
