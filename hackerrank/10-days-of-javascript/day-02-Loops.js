/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    for (let i of s){
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
            console.log(i);
        }
    }

    for (let i of s){
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
            continue;
        }
        console.log(i);
    }
}