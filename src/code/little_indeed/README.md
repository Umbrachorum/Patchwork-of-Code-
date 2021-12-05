<h1>TEAM CUILLERE : JoBoard</h1>
<h2>API and Database initialization</h2>
<h3>Database</h3>
<p>First open your mysql with the command: </p>
<ul>
	<li> mysql -u ${user} -p</li>
</ul>
<br>
<p>Now execute the following command inside your mysql board</p>
<ul>
	<li>create databasse joboard</li>
</ul>

<h3>API</h3>
<p>Execute the following command lines inside the folder "step7&8/job_api"</p>
<ul>
	<li>composer update</li>
	<li>composer install</li>
	<li>php artisan vendor:publish --provider="Laravel\Sanctum\SanctumServiceProvider"</li>
	<li>php artisan migrate</li>
</ul>
<p>Now rename the file .env.example to .env and enter your mysql username and password, withtout forgetting the name of the DB "joboard".</p>
<p>DB_DATABASE=joboard<br>
DB_USERNAME=user<br>
DB_PASSWORD=password
</p>
<p>Now execute the final command:</p>
<ul>
	<li>php artisan serve</li>
</ul>
<p>That's it the API is working !</p>
<p>You can now open step7&8/view/index.html inside your browser and start testing the app.</p>