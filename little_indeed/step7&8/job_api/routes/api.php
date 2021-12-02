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
use App\Http\Controllers\AuthController;
use App\Http\Controllers\AuthCompagny;


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

/*** Admin routes ***/


	/*Routes cities */
	Route::get('/cities/paginate', [CitiesController::class, 'paginatedIndex'])->middleware('adminCheck');
	Route::post('/cities', [CitiesController::class, 'store'])->middleware('adminCheck');
	Route::put('/cities/{id}', [CitiesController::class, 'update'])->middleware('adminCheck');
	Route::delete('/cities/{id}', [CitiesController::class, 'destroy'])->middleware('adminCheck');

	/*Routes child_fields */
	Route::get('/child_fields/paginate', [ChildFieldsController::class, 'paginatedIndex'])->middleware('adminCheck');
	Route::post('/child_fields', [ChildFieldsController::class, 'store'])->middleware('adminCheck');
	Route::put('/child_fields/{id}', [ChildFieldsController::class, 'update'])->middleware('adminCheck');
	Route::delete('/child_fields/{id}', [ChildFieldsController::class, 'destroy'])->middleware('adminCheck');

    /*Routes parent_fields */
	Route::get('/parent_fields/paginate', [ParentFieldsController::class, 'paginatedIndex'])->middleware('adminCheck');
    Route::post('/parent_fields', [ParentFieldsController::class, 'store'])->middleware('adminCheck');
    Route::put('/parent_fields/{id}', [ParentFieldsController::class, 'update'])->middleware('adminCheck');
    Route::delete('/parent_fields/{id}', [ParentFieldsController::class, 'destroy'])->middleware('adminCheck');

	/* Routes de Users */
	Route::post('/users/registerAdmin', [AuthController::class, 'registerAdmin'])->middleware('adminCheck');
	Route::get('/users', [UserController::class, 'index'])->middleware('adminCheck');
    Route::put('/user/admin/{id}', [UserController::class, 'update'])->middleware('adminCheck');
    Route::delete('/user/admin/{id}', [UserController::class, 'destroy'])->middleware('adminCheck');

	/* Routes de Companies */
	Route::get('/companies', [CompaniesController::class, 'index'])->middleware('adminCheck');
	Route::post('/companies/registerAdmin', [AuthCompagny::class, 'registerAdmin'])->middleware('adminCheck');
	Route::get('/companies/paginate', [CompaniesController::class, 'paginatedIndex'])->middleware('adminCheck');
    Route::put('/company/admin/{id}', [CompaniesController::class, 'update'])->middleware('adminCheck');
    Route::delete('/company/admin/{id}', [CompaniesController::class, 'destroy'])->middleware('adminCheck');

	/*Routes de Jobs*/
	Route::get('/jobs/paginate', [JobsController::class, 'paginatedBoard'])->middleware('adminCheck');
    Route::put('/job/admin/{id}', [JobsController::class, 'update'])->middleware('adminCheck');
    Route::delete('/job/admin/{id}', [JobsController::class, 'destroy'])->middleware('adminCheck');



/*** Unauthenticated Routes ***/

/* Routes de Users */
Route::post('/users/register', [AuthController::class, 'register']);
Route::post('/users/login', [AuthController::class, 'login']);
Route::post('/users/logout', [AuthController::class, 'logout']);

/* Routes de Companies */
Route::post('/companies/register', [AuthCompagny::class, 'register']);
Route::post('/companies/login', [AuthCompagny::class, 'login']);
Route::post('/companies/logout', [AuthCompagny::class, 'logout']);

/*Routes de Jobs*/
Route::get('/jobs', [JobsController::class, 'index']);
Route::get('/jobs/single/{id}', [JobsController::class, 'getJob']);
Route::get('/jobs_companies/{id}', [JobsController::class, 'getAllJobById']);

/*Routes job_applications*/
Route::get('/job_applications', [JobApplicationsController::class, 'index']);
Route::post('/job_applications', [JobApplicationsController::class, 'store']);

/*Routes cities*/
Route::get('/cities', [CitiesController::class, 'index']);
Route::get('/cities/single/{id}', [CitiesController::class, 'getCity']);

/*Routes parent_fields & child_fields*/
Route::get('/parent_fields', [ParentFieldsController::class, 'index']);
Route::get('/parent_fields/single/{id}', [ParentFieldsController::class, 'getParentField']);
Route::get('/child_fields', [ChildFieldsController::class, 'index']);
Route::get('/child_fields/single/{id}', [ChildFieldsController::class, 'getChildField']);

 Route::post('/jobs', [JobsController::class, 'store']);
/*** Auth Routes ***/

Route::group(['middleware' => ['auth:sanctum']], function() {

	/*Jobs */
    Route::put('/jobs/{id}', [JobsController::class, 'update']);
    Route::delete('/jobs/{id}', [JobsController::class, 'destroy']);

    /*Routes de Users*/
    Route::get('/users', [UserController::class, 'index']);
    // Route::post('/users', [UserController::class, 'store']);
    Route::get('/users/single/{id}', [UserController::class, 'getUser']);
    Route::put('/users/{id}', [UserController::class, 'update']);
    Route::delete('/users/{id}', [UserController::class, 'destroy']);
    Route::put('/password/{id}', [AuthController::class, 'changePassword']);

    /*Routes de Companies*/
    // Route::post('/companies', [CompaniesController::class, 'store']);
    Route::get('/companies/single/{id}', [CompaniesController::class, 'getCompany']);
    Route::put('/companies/{id}', [CompaniesController::class, 'update']);
    Route::delete('/companies/{id}', [CompaniesController::class, 'destroy']);

	/*Routes documents */
    Route::get('/documents', [DocumentsController::class, 'index']);
    Route::post('/documents', [DocumentsController::class, 'store']);
    Route::get('/documents/single/{id}', [DocumentsController::class, 'getDocument']);
    Route::put('/documents/user/{id}', [DocumentsController::class, 'update']);
    Route::delete('/documents/user/{id}', [DocumentsController::class, 'destroy']);

	/*Routes job_applications */
    Route::get('/job_applications/single/{id}', [JobApplicationsController::class, 'getJobApplication']);
    Route::put('/job_applications/{id}', [JobApplicationsController::class, 'update']);
    Route::delete('/job_applications/{id}', [JobApplicationsController::class, 'destroy']);
});
