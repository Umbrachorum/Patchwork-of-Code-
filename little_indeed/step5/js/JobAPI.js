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