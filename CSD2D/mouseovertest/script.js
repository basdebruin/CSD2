// mouseovertest script

let button = document.getElementById('touch');

button.addEventListener('pointerdown', function(e) {
    document.getElementById('output').innerHTML = "that was a " + e.pointerType + " " + e.type + " on a "+ e.target.nodeName;
})

// also add pointerup for mouseleave
button.addEventListener('pointerleave', function(e) {
    document.getElementById('output').innerHTML = "that was a " + e.pointerType + " " + e.type + " on a "+ e.target.nodeName;
})