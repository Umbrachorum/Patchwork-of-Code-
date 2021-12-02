<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateJobsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('jobs', function (Blueprint $table) {
            $table->id();
            $table->string('token_id', 30)->unique();
            $table->string('title', 100);
            $table->string('description', 255);
            $table->string('salary', 100);
			$table->integer('worktime');
			$table->foreignId('city_id')->constrained('cities');
			$table->foreignId('parent_fields_id')->constrained('parent_fields');
            $table->foreignId('child_fields_id')->constrained('child_fields');
            $table->foreignId('company_id')->constrained('companies');
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
        Schema::dropIfExists('jobs');
    }
}
