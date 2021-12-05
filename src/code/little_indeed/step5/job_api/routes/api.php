<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\UserController;
use App\Http\Controllers\JobsController;
use App\Http\Controllers\CitiesController;
use App\Http\Controllers\CompaniesController;
use App\Http\Controllers\ParentFieldsController;
use App\Http\Controllers\ChildFieldsController;
use App\Http\Controllers\DocumentsController;
use App\Http\Controllers\JobApplicationsController;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::middleware('auth:api')->get('/user', function (Request $request) {
    return $request->user();
});


/*Routes de Jobs*/
Route::get('/jobs', [JobsController::class, 'index']);
Route::post('/jobs', [JobsController::class, 'store']);
Route::get('/jobs/{id}', [JobsController::class, 'getJob']);
Route::put('/jobs/{id}', [JobsController::class, 'update']);
Route::delete('/jobs/{id}', [JobsController::class, 'destroy']);

/*Routes de Users*/
Route::get('/users', [UserController::class, 'index']);
Route::post('/users', [UserController::class, 'store']);
Route::get('/users/{id}', [UserController::class, 'getUser']);
Route::put('/users/{id}', [UserController::class, 'update']);
Route::delete('/users/{id}', [UserController::class, 'destroy']);

/*Routes de Companies*/
Route::get('/companies', [CompaniesController::class, 'index']);
Route::post('/companies', [CompaniesController::class, 'store']);
Route::get('/companies/{id}', [CompaniesController::class, 'getCompany']);
Route::put('/companies/{id}', [CompaniesController::class, 'update']);
Route::delete('/companies/{id}', [CompaniesController::class, 'destroy']);

/*Routes cities */
Route::get('/cities', [CitiesController::class, 'index']);
Route::post('/cities', [CitiesController::class, 'store']);
Route::get('/cities/{id}', [CitiesController::class, 'getCity']);
Route::put('/cities/{id}', [CitiesController::class, 'update']);
Route::delete('/cities/{id}', [CitiesController::class, 'destroy']);

/*Routes parent_fields */
Route::get('/parent_fields', [ParentFieldsController::class, 'index']);
Route::post('/parent_fields', [ParentFieldsController::class, 'store']);
Route::get('/parent_fields/{id}', [ParentFieldsController::class, 'getParentField']);
Route::put('/parent_fields/{id}', [ParentFieldsController::class, 'update']);
Route::delete('/parent_fields/{id}', [ParentFieldsController::class, 'destroy']);

/*Routes child_fields */
Route::get('/child_fields', [ChildFieldsController::class, 'index']);
Route::post('/child_fields', [ChildFieldsController::class, 'store']);
Route::get('/child_fields/{id}', [ChildFieldsController::class, 'getChildField']);
Route::put('/child_fields/{id}', [ChildFieldsController::class, 'update']);
Route::delete('/child_fields/{id}', [ChildFieldsController::class, 'destroy']);

/*Routes documents */
Route::get('/documents', [DocumentsController::class, 'index']);
Route::post('/documents', [DocumentsController::class, 'store']);
Route::get('/documents/{id}', [DocumentsController::class, 'getDocument']);
Route::put('/documents/{id}', [DocumentsController::class, 'update']);
Route::delete('/documents/{id}', [DocumentsController::class, 'destroy']);

/*Routes job_applications */
Route::get('/job_applications', [JobApplicationsController::class, 'index']);
Route::post('/job_applications', [JobApplicationsController::class, 'store']);
Route::get('/job_applications/{id}', [JobApplicationsController::class, 'getJobApplication']);
Route::put('/job_applications/{id}', [JobApplicationsController::class, 'update']);
Route::delete('/job_applications/{id}', [JobApplicationsController::class, 'destroy']);
