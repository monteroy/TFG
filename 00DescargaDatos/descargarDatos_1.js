
var request = require('request');
var sanitizeHtml = require('sanitize-html');
var jsonlint = require("jsonlint");
const fs = require('fs');

const url = 'https://www.saludcastillayleon.es/sanidad/cm/gallery/ENCUESTA%20REGIONAL%20DE%20SALUD%202003/Castilla%20y%20Leon/Tabla%20I.3.1.HTM';

function variables(body) {
    var regularDatos = /^.*\s*data*.*(-*\d{1,}\*\s*)*<\/td>*/igm;
    var datoID = 1;
    var datosArray = [];
    var datoEncontrado = regularDatos.exec(body);
    return { datoEncontrado, datoID, datosArray, regularDatos };
}

request.post(url, { text: true }, function (error, response, body) {
    var { datoEncontrado, datoID, datosArray, regularDatos } = variables(body);

    if (!error && response.statusCode == 200) {
        while (datoEncontrado != null) {
            textoDato = sanitizeHtml(datoEncontrado[1]);
            datoObject = { id: datoID, valor: datoEncontrado };
            datosArray.push(datoObject);
            datoEncontrado = regularDatos.exec(body);
            datoID++;
        }
        var datosJSON = JSON.stringify(datosArray);
        jsonlint.parse(datosJSON);
        datosJSON = datosJSON.replace(/\[/, '')
            .replace(/\{\"id":\d{1,},/g, '')
            .replace(/\"valor\":\[\"\<td class=\\"r b Data\\"\>/g, '')//etiqueta HTML
            .replace(/<\/td>",null]},/g, ';')//final de HTML
            .replace(/\s*/g, '')//quito los espacios en blanco
            .replace(/\.*/g, '')//quito los separadores de unidades
            .replace(/<\/td>",null]}/, '')//lo hace la ultima vez que lo encuentra aque] si lo quiero quitar
            .replace(/-;-/g, '0;0,00')
            .replace(/\d{0,},\d{0,};/g, '')
            .replace(/;100,00\]/, '');
        console.log(datosJSON);
        fs.writeFileSync('salidaJson.json', datosJSON);
    }

});



