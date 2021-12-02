function redirect_to_index(){
    document.location.href="../view/index.html";
}

function redirect_to_index_online(){
    if((window.sessionStorage.getItem('user') !== null && window.sessionStorage.getItem('user') !== undefined && JSON.parse(window.sessionStorage.getItem('user')).message != null) || (window.sessionStorage.getItem('companies') !== null && window.sessionStorage.getItem('companies') !== undefined)) {
        document.location.href="../view/index.html";
    }
}

function redirect_to_jobs(){
    if(window.sessionStorage.getItem('companies') !== null && window.sessionStorage.getItem('companies') !== undefined) {
        document.location.href="../view/jobs.html";
    }
}

function redirect_to_index_protection(){
    if(window.sessionStorage.getItem('companies') === null || window.sessionStorage.getItem('companies') === undefined) {
        document.location.href="../view/index.html";
    }
}

