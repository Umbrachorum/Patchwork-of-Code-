function docReady(fn) {
	// see if DOM is already available
	if (document.readyState === "complete" || document.readyState === "interactive") {
		// call on next available tick
		setTimeout(fn, 1);
	} else {
		document.addEventListener("DOMContentLoaded", fn);
	}
}

function initTabs() {
	const options = {
		duration: 300,
		onShow: null,
		swipeable: false,
		responsiveThreshold: Infinity
	};

	const tabsContainer = document.querySelector(".tabs");
	M.Tabs.init(tabsContainer, options);
}

function showDiv() {

	let button_login = document.querySelectorAll("a.switch_login");
	let button_signup = document.querySelector("a#switch_signup");

	button_login.forEach(element => {
		element.addEventListener("click", () => {
			document.querySelectorAll(".signin_tab").forEach(elem => {
				elem.style.display = "block";
			})
			document.querySelectorAll(".signup_tabs").forEach(elem => {
				elem.style.display = "none";
			});
		})
	});

	button_signup.addEventListener("click", () => {
		document.querySelectorAll(".signin_tab").forEach(elem => {
			elem.style.display = "none";
		})
		document.querySelectorAll(".signup_tabs").forEach(elem => {
			elem.style.display = "block";
		});
	});
}

docReady(() => {
    initTabs();
  	showDiv();
});