async function initPages(job_number) {
	var pages = Math.ceil(job_number / 8);
	// clearPagination();
	let pages_loaded = await appendPages(pages);
	initPageEvents();
}

async function appendPages(pages) {
	var page_ul = document.querySelector("ul.pagination");
	for(let index = 2; index <= pages; index++) {	
		page_ul.innerHTML += `<li id="page${index}" class="waves-effect page_index"><a href="#!">${index}</a></li>`;
	}
	return true;
}

async function clearPagination() {
	document.querySelector("ul.pagination").innerHTML = `<li id="page1" class="active page_index"><a href="#!">1</a></li>`;
}

async function initPageEvents() {

	document.querySelectorAll(`li.page_index`).forEach(element => {

		let page_number = element.innerText;

		element.addEventListener('click', async function() {

			console.log(page_number);
			changePaginationActive(page_number);
			let isSet = await setSessionPage(page_number);
			display_jobs()
			.then(() => {
				
			});
		});
	});
}

async function changePaginationActive(numb) {
	let last_page_index = await getSessionPage();
	let last_page = document.querySelector(`li#page${last_page_index}`);
	let current_page = document.querySelector(`li#page${numb}`);
	last_page.classList.remove("active");
	last_page.classList.add("waves-effect");
	current_page.classList.add("active");
	current_page.classList.remove("waves-effect");
}

async function initActivePage() {
	if(window.sessionStorage.getItem('page') !== undefined && window.sessionStorage.getItem('page') !== null) {
		let first_page = document.querySelector(`li#page1`);
		let init_page = document.querySelector(`li#page${window.sessionStorage.getItem('page')}`);
		first_page.classList.remove("active");
		first_page.classList.add("waves-effect");
		init_page.classList.add("active");
		init_page.classList.remove("waves-effect");
	}
}

async function setSessionPage(page_number) {
	window.sessionStorage.setItem('page', page_number);
	return true;
}

async function getSessionPage() {
	let page_numb = window.sessionStorage.getItem('page');
	return page_numb;
}