<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateJobApplicationsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('job_applications', function (Blueprint $table) {
            $table->id();
            $table->string('token_id', 30)->unique();
            $table->foreignId('user_id')->constrained('users');
            $table->foreignId('job_id')->constrained('jobs');
            $table->foreignId('company_id')->constrained('companies');
            $table->string('message', 255);
			$table->binary('cv')->nullable();
			$table->binary('motivation_letter')->nullable();
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('job_applications');
    }
}
