const DEFAULT_HEADERS = {
  	"Content-Type": "application/json",
	"Accept": "application/json"
};

function getter(path) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "GET",
			headers: DEFAULT_HEADERS,
		})
		.then((response) => response.json())
		.then((data) => resolve(data))
		.catch(reject);
	});
}

function getterWithToken(path, token) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "GET",
			headers: {
				"Content-Type": "application/json",
				"Accept": "application/json",
				'Authorization': 'Bearer ' + token
			}
		})
		.then((response) => response.json())
		.then((data) => resolve(data))
		.catch(reject);
	});
}

function postReq(path, body) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "POST",
			headers: DEFAULT_HEADERS,
			body: body
		})
		.then((response) => response.json())
		.then((data) => resolve(data))
		.catch(reject);
	});
}


function postReqJob(path, body, token) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Accept": "application/json",
				'Authorization': 'Bearer ' + token
			},
			body: body
		})
		.then((response) => response.json())
		.then((data) => resolve(data))
		.catch(reject);
	});
}

function upReqLog(path, token) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Accept": "application/json",
				'Authorization': 'Bearer ' + token
			},
		})
			.then((response) => response.json())
			.then((data) => resolve(data))
			.catch(reject);
	});
}

function upReq(path, body, token) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "PUT",
			headers: {
				"Content-Type": "application/json",
				"Accept": "application/json",
				'Authorization': 'Bearer ' + token
			},
			body: body
		})
			.then((response) => response.json())
			.then((data) => resolve(data))
			.catch(reject);
	});
}

function delReq(path, token) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "DELETE",
			headers: {
				"Content-Type": "application/json",
				"Accept": "application/json",
				'Authorization': 'Bearer ' + token
			},
		})
			.then((response) => response.json())
			.then((data) => resolve(data))
			.catch(reject);
	});
}

function delReqWithToken(path, body, token) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "DELETE",
			headers: {
				"Content-Type": "application/json",
				"Accept": "application/json",
				'Authorization': 'Bearer ' + token
			},
			body: body
		})
		.then((response) => response.json())
		.then((data) => resolve(data))
		.catch(reject);
	});
}