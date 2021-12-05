<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateCompaniesTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('companies', function (Blueprint $table) {
            $table->id();
            $table->string('token_id', 30)->unique();
            $table->string('name', 100);
            $table->string('description', 255);
            $table->foreignId('city_id')->constrained('cities');
            $table->string('email')->unique();
            $table->string('password', 100);
            $table->tinyInteger('premium');
			$table->tinyInteger('isCompany');
            $table->binary('logo')->nullable();
			$table->rememberToken();
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
        Schema::dropIfExists('companies');
    }
}
