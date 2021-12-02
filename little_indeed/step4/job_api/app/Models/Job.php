<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Job extends Model
{
	protected $fillable = [
		'id',
		'token_id',
		'title',
		'description',
		'salary',
		'city_id',
		'worktime',
		'parent_fields_id',
		'child_fields_id',
		'company_id',
		'created_at',
		'updated_at',
	];
}
