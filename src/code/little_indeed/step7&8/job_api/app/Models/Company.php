<?php

namespace App\Models;

namespace App\Models;
use Illuminate\Contracts\Auth\MustVerifyEmail;
use Illuminate\Foundation\Auth\User as Authenticatable;
use Illuminate\Notifications\Notifiable;
use Laravel\Sanctum\HasApiTokens;
use Illuminate\Database\Eloquent\Model;

class Company extends Authenticatable
{
     use Notifiable, HasApiTokens;

            /**
             * The attributes that are mass assignable.
             *
             * @var array
             */
            protected $fillable = [
                'description', 'email', 'password', 'token_id', 'city_id', 'name', "premium", 'isCompany'
            ];

            /**
             * The attributes that should be hidden for arrays.
             *
             * @var array
             */
            protected $hidden = [
                'password', 'remember_token', 'isAdmin'
            ];

            /**
             * The attributes that should be cast to native types.
             *
             * @var array
             */
            protected $casts = [
                'email_verified_at' => 'datetime',
            ];
}
