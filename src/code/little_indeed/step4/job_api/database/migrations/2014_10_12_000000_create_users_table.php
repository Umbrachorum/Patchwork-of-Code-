<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateUsersTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('users', function (Blueprint $table) {
            $table->id();
            $table->string('token_id', 30)->unique();
            $table->string('lastname', 100);
            $table->string('firstname', 100);
            $table->string('phone_number', 100);
            $table->date('birthdate');
            $table->string('email', 100)->unique();
            $table->string('password', 100);
            $table->tinyInteger('premium');
            $table->tinyInteger('isAdmin');
			$table->tinyInteger('isCompany');
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
        Schema::dropIfExists('users');
    }
}

