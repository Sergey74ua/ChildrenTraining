//Симулятор колонии муравьев

var model, view, control;

let listClass=[
    'AI',
    'Action',
    'Ant',
    'Colony',
    'Items',
    'Model',
    'View',
    'Control'
];

for (let name of listClass) {
    getScript(name);
}

function getScript(name) {
    let script=document.createElement('script');
    script.type='application/javascript';
    script.src='js/'+name+'.js';
    document.body.appendChild(script);
}

window.onload=() => {
    model=new Model();
    view=new View();
    control=new Control();
}