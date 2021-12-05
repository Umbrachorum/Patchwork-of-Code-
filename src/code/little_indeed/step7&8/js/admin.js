function returnJob(job, i) {
	let jobRow = `
	<li class="collection-item avatar">
		<i class="material-icons circle">folder</i>
		<div class="container row_container">
			<div class="row">
				<div class="col s5 m5 l4">
					<h4 class="title">${job.title}</h4>
				</div>
				<div class="col s5 m5 l4">						
					<p>${job.company_name}</p>
				</div>
				<div class="col l4">
					<p class="job_admin_desc hide-on-med-and-down">${job.description}</p>
				</div>
			</div>
		</div>
		<a href="#modal${i}" class="modal-trigger btn-flat waves-effect waves-light secondary-content modal_button">
			<i class="material-icons right">border_color</i>
		</a>
	</li>`;
	return jobRow;
}
function returnUser(user, i) {
	let userRow = `
	<li class="collection-item avatar">
		<i class="material-icons circle">folder</i>
		<div class="container row_container">
			<div class="row">
				<div class="col s5 m5 l4">
					<h4 class="title">${user.firstname}</h4>
				</div>
				<div class="col s5 m5 l4">						
					<p>${user.lastname}</p>
				</div>
				<div class="col l4">
					<p class="job_admin_desc hide-on-med-and-down">${user.email}</p>
				</div>
			</div>
		</div>
		<a href="#modal${i}" class="modal-trigger btn-flat waves-effect waves-light secondary-content modal_button">
			<i class="material-icons right">border_color</i>
		</a>
	</li>`;
	return userRow;
}
function returnCompanies(company, i) {
	let companyRow = `
	<li class="collection-item avatar">
		<i class="material-icons circle">folder</i>
		<div class="container row_container">
			<div class="row">
				<div class="col s5 m5 l4">
					<h4 class="title">${company.name}</h4>
				</div>
				<div class="col s5 m5 l4">						
					<p>${company.email}</p>
				</div>
				<div class="col l4">
					<p class="job_admin_desc hide-on-med-and-down">${company.description}</p>
				</div>
			</div>
		</div>
		<a href="#modal${i}" class="modal-trigger btn-flat waves-effect waves-light secondary-content modal_button">
			<i class="material-icons right">border_color</i>
		</a>
	</li>`;
	return companyRow;
}
function returnChild(child, i) {
	let childRow = `
	<li class="collection-item avatar">
		<i class="material-icons circle">folder</i>
		<div class="container row_container">
			<div class="row">
				<div class="col s5 m5 l5">
					<h4 class="title">${child.name}</h4>
				</div>
				<div class="col s5 m5 l5">						
					<p>Parent: ${child.parent_name}</p>
				</div
			</div>
		</div>
		<a href="#modal${i}" class="modal-trigger btn-flat waves-effect waves-light secondary-content modal_button">
			<i class="material-icons right">border_color</i>
		</a>
	</li>`;
	return childRow;
}
function returnParent(parent, i) {
	let parentRow = `
	<li class="collection-item avatar">
		<i class="material-icons circle">folder</i>
		<div class="container row_container">
			<div class="row">
				<div class="col s10 m10 l10">
					<h4 class="title">${parent.name}</h4>
				</div>
			</div>
		</div>
		<a href="#modal${i}" class="modal-trigger btn-flat waves-effect waves-light secondary-content modal_button">
			<i class="material-icons right">border_color</i>
		</a>
	</li>`;
	return parentRow;
}
function returnCity(city, i) {
	let cityRow = `
	<li class="collection-item avatar">
		<i class="material-icons circle">folder</i>
		<div class="container row_container">
			<div class="row">
				<div class="col s10 m5 l5">
					<h4 class="title">${city.name}</h4>
				</div>
				<div class="col s10 m5 l5">
					<h4 class="title">${city.zipcode}</h4>
				</div>
			</div>
		</div>
		<a href="#modal${i}" class="modal-trigger btn-flat waves-effect waves-light secondary-content modal_button">
			<i class="material-icons right">border_color</i>
		</a>
	</li>`;
	return cityRow;
}

async function clearPanels(table) {
	document.querySelector("ul.table_container").innerHTML = `<li class="collection-header"><h4>${table}</h4></li>`;
	return;
}
async function clearModals() {
	document.querySelector("div#modals_div").innerHTML = "";
	return;
}

async function switchPanels(cities, parent_fields, child_fields, companies) {

	let tables = document.querySelectorAll("div#panel_collection a");
	tables.forEach(element => {
		element.addEventListener('click', async function() {
			window.sessionStorage.removeItem('page');
			displayTable(element.id, cities, parent_fields, child_fields, companies)
			.then(async () => {
				await setNewActiveTable(element);
				await initAddButton(cities, parent_fields, child_fields, companies);
				initModals();
				initPages(window.sessionStorage.getItem('pages_total'), cities, parent_fields, child_fields, companies);
				initActivePage();
			});
		});
	});
}

function appendList(response, i, panel) {
	return new Promise(resolve => {
		switch(panel) {
			case 'jobs':
				document.querySelector("ul.table_container").innerHTML += returnJob(response.data[i], i);
				resolve();
				break;
			case 'users':
				document.querySelector("ul.table_container").innerHTML += returnUser(response.data[i], i);
				resolve();
				break;
			case 'companies':
				document.querySelector("ul.table_container").innerHTML += returnCompanies(response.data[i], i);
				resolve();
				break;
			case 'child_fields':
				document.querySelector("ul.table_container").innerHTML += returnChild(response.data[i], i);
				resolve();
				break;
			case 'parent_fields':
				document.querySelector("ul.table_container").innerHTML += returnParent(response.data[i], i);
				resolve();
				break;
			case 'cities':
				document.querySelector("ul.table_container").innerHTML += returnCity(response.data[i], i);
				resolve();
				break;
		}
		
	});
}

function getJobs(page, cities, parent_fields, child_fields, companies) {
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	return getterWithToken(`jobs/paginate?page=${page}`, token).then((response) => {
		return new Promise(async (resolve) => {
			await clearPanels("Jobs");
			await clearModals();
			for (let i = 0; i < response.data.length; i++) {
				appendList(response, i, 'jobs')
				.then(async function () {
					let modalOK = await initModalForm("jobs", response.data[i], i, cities, parent_fields, child_fields, companies);
				});
			}
			window.sessionStorage.setItem('pages_total', response.total);
			resolve();
		});
	});
}
function getUsers(page) {
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	return getterWithToken(`users?page=${page}`, token).then((response) => {
		return new Promise(async (resolve) => {
			await clearPanels("Users");
			await clearModals();
			for (let i = 0; i < response.data.length; i++) {
				appendList(response, i, 'users')
				.then(async function () {
					let modalOK = await initModalForm("users", response.data[i], i);
				});
			}
			window.sessionStorage.setItem('pages_total', response.total);
			resolve();
		});
	});
}
function getCompanies(page, cities) {
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	return getterWithToken(`companies/paginate?page=${page}`, token).then((response) => {
		return new Promise(async (resolve) => {
			await clearPanels('Companies');
			await clearModals();
			for (let i = 0; i < response.data.length; i++) {
				appendList(response, i, 'companies')
				.then(async function () {
					let modalOK = await initModalForm("companies", response.data[i], i, cities);
				});
			}
			window.sessionStorage.setItem('pages_total', response.total);
			resolve();
		});
	});
}
function getChilds(page, cities, parent_fields) {
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	return getterWithToken(`child_fields/paginate?page=${page}`, token).then((response) => {
		return new Promise(async (resolve) => {
			await clearPanels("Child Fields");
			await clearModals();
			for (let i = 0; i < response.data.length; i++) {
				appendList(response, i, 'child_fields')
				.then(async function () {
					let modalOK = await initModalForm("child_fields", response.data[i], i, cities, parent_fields);
				});
			}
			window.sessionStorage.setItem('pages_total', response.total);
			resolve();
		});
	});
}
function getParents(page) {
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	return getterWithToken(`parent_fields/paginate?page=${page}`, token).then((response) => {
		return new Promise(async (resolve) => {
			await clearPanels("Parent Fields");
			await clearModals();
			for (let i = 0; i < response.data.length; i++) {
				appendList(response, i, 'parent_fields')
				.then(async function () {
					let modalOK = await initModalForm("parent_fields", response.data[i], i);
				});
			}
			window.sessionStorage.setItem('pages_total', response.total);
			resolve();
		});
	});
}
function getCities(page) {
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	return getterWithToken(`cities/paginate?page=${page}`, token).then((response) => {
		return new Promise(async (resolve) => {
			await clearPanels('Cities');
			await clearModals();
			for (let i = 0; i < response.data.length; i++) {
				appendList(response, i, 'cities')
				.then(async function () {
					let modalOK = await initModalForm("cities", response.data[i], i);
				});
			}
			window.sessionStorage.setItem('pages_total', response.total);
			resolve();
		});
	});
}

function displayTable(table_type, cities, parent_fields, child_fields, companies) {

	var page = 1;
	if(window.sessionStorage.getItem('page') !== undefined && window.sessionStorage.getItem('page') !== null) {
		page = window.sessionStorage.getItem('page');
	} else {
		window.sessionStorage.setItem('page', page);
	}
	switch (table_type) {
		case 'job_panel':
			return getJobs(page, cities, parent_fields, child_fields, companies);
		case 'user_panel':
			return getUsers(page);
		case 'company_panel':
			return getCompanies(page, cities);
		case 'childs_fields_panel':
			return getChilds(page, cities, parent_fields);
		case 'parents_fields_panel':
			return getParents(page);
		case 'cities_panel':
			return getCities(page);		
	}
}

function nav_working()
{
	draw_navbar();
	job_button();
	choose_url_profile();
	sidenav();
	select_login_logout();
}

async function setActiveTable(panel) {
	window.sessionStorage.setItem('active_table', panel);
	return;
}
async function setNewActiveTable(element) {
	if(window.sessionStorage.getItem('active_table') !== null && window.sessionStorage.getItem('active_table') !== undefined) {
		let active_table = window.sessionStorage.getItem('active_table');
		document.querySelector(`a#${active_table}`).classList.remove('active');
		element.classList.add('active');
		window.sessionStorage.setItem('active_table', element.id);
	}
}

docReady(async () => {
	var cities = await optionCities();
	var parent_fields = await optionParentFields();
	var child_fields = await optionChildFields();
	var companies = await optionCompanies();
	await switchPanels(cities, parent_fields, child_fields, companies);
	nav_working();
	displayTable("job_panel", cities, parent_fields, child_fields, companies)
	.then(async () => {
		await setActiveTable('job_panel');
		await initAddButton(cities, parent_fields, child_fields, companies);
		initModals();
		initPages(window.sessionStorage.getItem('pages_total'), cities, parent_fields, child_fields, companies);
		initActivePage();
	});
	logout();
});