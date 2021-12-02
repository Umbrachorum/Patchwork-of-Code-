function returnJobModal(job, i) {
	let jobModal = `<div id="modal${i}" class="modal modal-fixed-footer">
		<div class="modal-content">
			<div class="row">
				<form class="col s12">
					<div class="row">
						<div class="col s12 m8 l8">
							<input placeholder="Title" name="title" id="title_job${i}" type="text" class="validate" value="${job.title}"/>
							<label for="title_job${i}"> Title </label>
						</div>
					</div>
					<div class="row">
						<div class="col s12">
							<textarea maxlength="500" placeholder="Description" name="description" id="description_job${i}" class="materialize-textarea">${job.description}</textarea>
							<label for="description_job${i}"> Description </label>
						</div>
					</div>
					<div class="row">
						<div class="col s12 m6 l6">
							<input placeholder="Salary" name="salary" id="salary_job${i}" type="text" class="validate" value="${job.salary}"/>
							<label for="salary_job${i}"> Salary </label>
						</div>
						<div class="col s12 m6 l6">
							<input placeholder="Worktime" name="worktime" id="time_job${i}" type="text" class="validate" value="${job.worktime}"/>
							<label for="time_job${i}"> Worktime </label>
						</div>
					</div>
					<div class="input-field select_cities">
						<select name="city_id" id="city_id${i}">
						</select>
					</div>
					<label for="city_id${i}"> City </label>
					<div class="input-field select_parent_fields">
						<select name="parent_fields_id" id="parent_id${i}">
						</select>
					</div>
					<label for="parent_id${i}"> Parent fields </label>
					<div class="input-field select_child_fields">
						<select name="child_fields_id" id="child_id${i}">
						</select>
					</div>
					<label for="child_id${i}"> Child fields </label>
					<div class="input-field select_companies">
						<select name="company_id" id="company_id${i}">
						</select>
					</div>
					<label for="company_id${i}"> Companies </label>
					<p id="error${i}" class="modal_error"></p>
					<p class="modal_updated"></p>
				</form>
			</div>
			<div class="row">
				<div class="col s4 m2 l2">
					<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
						<i class="material-icons right">send</i>
					</button>
				</div>
				<div id="delete_btn_div${i}" class="col s4 m2 l2">
					<button id="delete_btn${i}" class="waves-effect btn-flat delete_button">Delete
						<i class="material-icons right">delete</i>
					</button>
				</div>
				<div id="delete_conf_div${i}" class="col s4 m2 l2">
					<button id="delete_btn_conf${i}" class="waves-effect btn-flat delete_button">YES
					</button>
					<button id="delete_btn_inf${i}" class="waves-effect btn-flat modal_button">NO
					</button>
				</div>
			</div>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return jobModal;
}
function returnUserModal(user, i) {
	let userModal = `<div id="modal${i}" class="modal modal-fixed-footer">
		<div class="modal-content">
			<form class="col s12">
				<div class="row">
					<div class="col s12 m6 l6">
						<input name="firstname" id="firstname${i}" type="text" class="validate" value="${user.firstname}"/>
						<label for="firstname${i}"> Firstname </label>
					</div>
					<div class="col s12 m6 l6">
						<input name="lastname" id="lastname${i}" type="text" class="validate" value="${user.lastname}"/>
						<label for="lastname${i}"> Lastname </label>
					</div>
				</div>
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="email" type="email" id="email${i}" class="activate" value="${user.email}"/>
						<label for="email${i}"> Email </label>
					</div>
				</div>
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="phone_number" type="text" id="phone_number${i}" class="activate" value="${user.phone_number}"/>
						<label for="phone_number${i}"> Phone number </label>
					</div>
				</div>
				<div class="row">
					<div class="col s12 m8 l8">
						<input placeholder="Birthdate" name="birthdate" id="birthdate${i}" type="date" class="validate" min="1900-01-01" value="${user.birthdate}"/>
						<label for="birthdate${i}">Birthdate</label>
					</div>
				</div>
				<div class="row">
					<div class="col s12 m8 l8">
						<span class="press_to_reset">Change password</span>
					</div>
				</div>
				<div class="reset_password">
					<div class="row">
						<div class="input-field col s12 m8 l8">
							<input name="password" type="password" id="password${i}" class="activate" value=""/>
							<label for="password${i}"> Password </label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12 m8 l8">
							<input name="password_confirmation" type="password" id="password_confirmation${i}" class="activate" value=""/>
							<label for="password_confirmation${i}"> Password Confirmation </label>
						</div>
					</div>
				</div>
				<p id="error${i}" class="modal_error"></p>
				<p class="modal_updated"></p>
			</form>
			<div class="row">
				<div class="col s4 m2 l2">
					<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
						<i class="material-icons right">send</i>
					</button>
				</div>
				<div id="delete_btn_div${i}" class="col s4 m2 l2">
					<button id="delete_btn${i}" class="waves-effect btn-flat delete_button">Delete
						<i class="material-icons right">delete</i>
					</button>
				</div>
				<div id="delete_conf_div${i}" class="col s4 m2 l2">
					<button id="delete_btn_conf${i}" class="waves-effect btn-flat delete_button">YES
					</button>
					<button id="delete_btn_inf${i}" class="waves-effect btn-flat modal_button">NO
					</button>
				</div>
			</div>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return userModal;
}
function returnCompanyModal(company, i) {
	let companyModal = `<div id="modal${i}" class="modal modal-fixed-footer">
		<div class="modal-content">
			<form class="col s12">
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="name" id="name${i}" type="text" class="validate" value="${company.name}"/>
						<label for="name${i}"> Name </label>
					</div>
				</div>
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="email" type="email" id="email${i}" class="activate" value="${company.email}"/>
						<label for="email${i}"> Email </label>
					</div>
				</div>
				<div class="row">
					<div class="col s12">
						<textarea maxlength="500" placeholder="Description" name="description" id="description_comp${i}" class="materialize-textarea">${company.description}</textarea>
						<label for="description_comp${i}"> Description </label>
					</div>
				</div>
				<div class="input-field select_cities">
					<select name="city_id" id="city_id${i}"></select>
				</div>
				<label for="city_id${i}"> City </label>
				<div class="row">
					<div class="col s12 m8 l8">
						<span class="press_to_reset">Change password</span>
					</div>
				</div>
				<div class="reset_password">
					<div class="row">
						<div class="input-field col s12 m8 l8">
							<input name="password" type="password" id="password${i}" class="activate" value=""/>
							<label for="password${i}"> Password </label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12 m8 l8">
							<input name="password_confirmation" type="password" id="password_confirmation${i}" class="activate" value=""/>
							<label for="password_confirmation${i}"> Password Confirmation </label>
						</div>
					</div>
				</div>
				<p id="error${i}" class="modal_error"></p>
				<p class="modal_updated"></p>
			</form>
			<div class="row">
				<div class="col s4 m2 l2">
					<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
						<i class="material-icons right">send</i>
					</button>
				</div>
				<div id="delete_btn_div${i}" class="col s4 m2 l2">
					<button id="delete_btn${i}" class="waves-effect btn-flat delete_button">Delete
						<i class="material-icons right">delete</i>
					</button>
				</div>
				<div id="delete_conf_div${i}" class="col s4 m2 l2">
					<button id="delete_btn_conf${i}" class="waves-effect btn-flat delete_button">YES
					</button>
					<button id="delete_btn_inf${i}" class="waves-effect btn-flat modal_button">NO
					</button>
				</div>
			</div>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return companyModal;
}
function returnParentModal(parent_field, i) {
	let parentModal = `<div id="modal${i}" class="modal modal-fixed-footer">
		<div class="modal-content">
			<form class="col s12">
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="name" id="name${i}" type="text" class="validate" value="${parent_field.name}"/>
						<label for="name${i}"> Name </label>
					</div>
				</div>
				<p id="error${i}" class="modal_error"></p>
				<p class="modal_updated"></p>
			</form>
			<div class="row">
				<div class="col s4 m2 l2">
					<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
						<i class="material-icons right">send</i>
					</button>
				</div>
				<div id="delete_btn_div${i}" class="col s4 m2 l2">
					<button id="delete_btn${i}" class="waves-effect btn-flat delete_button">Delete
						<i class="material-icons right">delete</i>
					</button>
				</div>
				<div id="delete_conf_div${i}" class="col s4 m2 l2">
					<button id="delete_btn_conf${i}" class="waves-effect btn-flat delete_button">YES
					</button>
					<button id="delete_btn_inf${i}" class="waves-effect btn-flat modal_button">NO
					</button>
				</div>
			</div>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return parentModal;
}
function returnChildModal(child_field, i) {
	let childFieldModal = `<div id="modal${i}" class="modal modal-fixed-footer">
		<div class="modal-content">
			<form class="col s12">
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="name" id="name${i}" type="text" class="validate" value="${child_field.name}"/>
						<label for="name${i}"> Name </label>
					</div>
				</div>
				<div class="input-field select_parent_fields">
					<select name="parent_fields_id" id="parent_id${i}">
					</select>
				</div>
				<label for="parent_id${i}"> Parent fields </label>
				<p id="error${i}" class="modal_error"></p>
				<p class="modal_updated"></p>
			</form>
			<div class="row">
				<div class="col s4 m2 l2">
					<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
						<i class="material-icons right">send</i>
					</button>
				</div>
				<div id="delete_btn_div${i}" class="col s4 m2 l2">
					<button id="delete_btn${i}" class="waves-effect btn-flat delete_button">Delete
						<i class="material-icons right">delete</i>
					</button>
				</div>
				<div id="delete_conf_div${i}" class="col s4 m2 l2">
					<button id="delete_btn_conf${i}" class="waves-effect btn-flat delete_button">YES
					</button>
					<button id="delete_btn_inf${i}" class="waves-effect btn-flat modal_button">NO
					</button>
				</div>
			</div>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return childFieldModal;
}
function returnCityModal(city, i) {
	let cityModal = `<div id="modal${i}" class="modal modal-fixed-footer">
		<div class="modal-content">
			<form class="col s12">
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="name" id="name${i}" type="text" class="validate" value="${city.name}"/>
						<label for="name${i}"> Name </label>
					</div>
				</div>
				<div class="row">
					<div class="col s12 m8 l8">
						<input name="zipcode" id="zipcode${i}" type="text" class="validate" value="${city.zipcode}"/>
						<label for="zipcode${i}"> Zipcode </label>
					</div>
				</div>
				<p id="error${i}" class="modal_error"></p>
				<p class="modal_updated"></p>
			</form>
			<div class="row">
				<div class="col s4 m2 l2">
					<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
						<i class="material-icons right">send</i>
					</button>
				</div>
				<div id="delete_btn_div${i}" class="col s4 m2 l2">
					<button id="delete_btn${i}" class="waves-effect btn-flat delete_button">Delete
						<i class="material-icons right">delete</i>
					</button>
				</div>
				<div id="delete_conf_div${i}" class="col s4 m2 l2">
					<button id="delete_btn_conf${i}" class="waves-effect btn-flat delete_button">YES
					</button>
					<button id="delete_btn_inf${i}" class="waves-effect btn-flat modal_button">NO
					</button>
				</div>
			</div>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return cityModal;
}

async function appendCities(index, object, response) {
	let element = document.querySelector(`select#city_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block";
	element.value = object.city_id;
}
async function appendParentFields(index, object, response) {
	let element = document.querySelector(`select#parent_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block"; 
	element.value = object.parent_fields_id;	
}
async function appendChildFields(index, object, response) {
	let element = document.querySelector(`select#child_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block";
	element.value = object.child_fields_id;
}
async function appendCompanies(index, object, response) {
	let element = document.querySelector(`select#company_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block";
	element.value = object.company_id;
}

async function optionCities() {
	let response = getter("cities").then(response => {
		return response;
	});
	return response;
	
}
async function optionParentFields() {
	let response = getter("parent_fields").then(response => {
		return response;
	});
	return response;
}
async function optionChildFields() {
	let response = getter("child_fields").then(response => {
		return response;
	});
	return response;
}
async function optionCompanies() {
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	let response = getterWithToken("companies", token).then(response => {
		return response;
	});
	return response;
}

function confirmEdit(i) {
	let element = document.querySelector(`div#modal${i} p.modal_updated`);
	let confirmationMessage = `Item updated !`;
	element.innerHTML = confirmationMessage;	
}

async function appendModal(keyword, object, i) {
	switch(keyword) {
		case "jobs":
			document.querySelector("div#modals_div").innerHTML += returnJobModal(object, i);
			return;
		case "users":
			document.querySelector("div#modals_div").innerHTML += returnUserModal(object, i);
			return;
		case "companies":
			document.querySelector("div#modals_div").innerHTML += returnCompanyModal(object, i);
			return;
		case "parent_fields":
			document.querySelector("div#modals_div").innerHTML += returnParentModal(object, i);
			return;
		case "child_fields":
			document.querySelector("div#modals_div").innerHTML += returnChildModal(object, i);
			return;
		case "cities":
			document.querySelector("div#modals_div").innerHTML += returnCityModal(object, i);
			return;
	}
}

async function initDeleteButton(keyword, object, i, cities, parent_fields, child_fields, companies) {
	let path = "";
	switch(keyword) {
		case "jobs":
			path = `job/admin/${object.id}`
			break;
		case "users":
			path = `user/admin/${object.id}`
			break;
		case "companies":
			path = `company/admin/${object.token_id}`
			break;
		case "parent_fields":
			path = `parent_fields/${object.id}`
			break;
		case "child_fields":
			path = `child_fields/${object.id}`
			break;
		case "cities":
			path = `cities/${object.id}`
			break;
	}
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	document.querySelector(`div#delete_conf_div${i}`).style.display = "none";
	document.querySelector(`button#delete_btn${i}`).addEventListener('click', () => {
		document.querySelector(`div#delete_conf_div${i}`).style.display = "block";
		document.querySelector(`div#delete_btn_div${i}`).style.display = "none";
	});
	document.querySelector(`button#delete_btn_inf${i}`).addEventListener('click', () => {
		document.querySelector(`div#delete_conf_div${i}`).style.display = "none";
		document.querySelector(`div#delete_btn_div${i}`).style.display = "block";
	});
	document.querySelector(`button#delete_btn_conf${i}`).addEventListener('click', () => {
		delReqWithToken(path, token).then(response => {
			if(!response.OK || !response['200'])
				console.log(response);
			displayTable(window.sessionStorage.getItem('active_table'), cities, parent_fields, child_fields, companies)
			.then(async () => {
				await initAddButton(cities, parent_fields, child_fields, companies);
				initModals();
				initPages(window.sessionStorage.getItem('pages_total'), cities, parent_fields, child_fields, companies);
				initActivePage();
			});
		});
	});
}

async function initModalForm(keyword, object, i, cities, parent_fields, child_fields, companies) {
	await appendModal(keyword, object, i);
	switch(keyword) {
		case "jobs":
			await appendCities(i, object, cities);
			await appendParentFields(i, object, parent_fields);
			await appendChildFields(i, object, child_fields);
			await appendCompanies(i, object, companies);
			break;
		case "companies":
			await appendCities(i, object, cities);
			break;
		case "child_fields":
			await appendParentFields(i, object, parent_fields);
			break;
	}
	await initDeleteButton(keyword, object, i, cities, parent_fields, child_fields, companies);
	let element = document.querySelector(`button#send_btn${i}`);
	element.addEventListener('click', async function() {
		let inputCheck = await sendUpdateForm(keyword, object, i, cities, parent_fields, child_fields, companies);
		if(inputCheck === false) {
			document.querySelector(`div#modal${i} p.modal_updated`).innerText = "";
			document.querySelector(`p#error${i}`).innerText = "Please fill in all the fields";
		}	
	});
	return true;
}

async function checkInputs(i) {
	let collection = document.querySelector(`div#modal${i} form`);
	for (let input of collection) {
		if(input.value === null || input.value === undefined || input.value === "") {
			return false;
		} 
	}
	return true;
}

async function errorsHandling(response, i) {
	if((response.OK !== null && response.OK !== undefined) || (response.user !== null && response.user !== undefined)) {
		document.querySelector(`p#error${i}`).innerText = "";
		confirmEdit(i);
	} else if (response.errors !== undefined && response.errors.email !== null && response.errors.email !== undefined) {
		document.querySelector(`div#modal${i} p.modal_updated`).innerText = "";
		document.querySelector(`p#error${i}`).innerText = "The email must be a valid email address";
	} else if (response.errors !== undefined && response.errors.phone_number !== null && response.errors.phone_number !== undefined) {
		document.querySelector(`div#modal${i} p.modal_updated`).innerText = "";
		document.querySelector(`p#error${i}`).innerText = "The phone number must be a number";
	}
}

async function sendUpdateForm(keyword, object, i, cities, parent_fields, child_fields, companies) {
	let inputCheck = await checkInputs(i);
	if(inputCheck === false)
		return false;
	let collection = document.querySelector(`div#modal${i} form`);
	var request = {};
	for(let input of collection) {
		if(input.localName === 'textarea') {
			request[`${input.name}`] = input.value;
		} else {
			request[`${input.name}`] = input.value;
		}
	}
	let body = JSON.stringify(request);
	let path = "";

	switch(keyword) {
		case "jobs":
			path = `job/admin/${object.id}`;
			break;
		case "users":
			path = `user/admin/${object.token_id}`;
			break;
		case "companies":
			path = `company/admin/${object.token_id}`;
			break;
		case "parent_fields":
			path = `parent_fields/${object.id}`;
			break;
		case "child_fields":
			path = `child_fields/${object.id}`;
			break;
		case "cities":
			path = `cities/${object.id}`;
			break;
	}
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	upReq(path, body, token)
	.then((response) => {
		errorsHandling(response, i);
		displayTable(window.sessionStorage.getItem('active_table'), cities, parent_fields, child_fields, companies)
		.then(async () => {
			await initAddButton(cities, parent_fields, child_fields, companies);
			initModals();
			initPages(window.sessionStorage.getItem('pages_total'), cities, parent_fields, child_fields, companies);
			initActivePage();
		});
	})
	.catch(error => console.log(error));
}

function initModals() {
	var modal_elems = document.querySelectorAll(".modal");
	var modal_instances = M.Modal.init(modal_elems, {preventScrolling: true});
}

function initSelects() {
	var select_elems = document.querySelectorAll('select');
    var select_instances = M.FormSelect.init(select_elems);
}