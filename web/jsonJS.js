let json='{'+    
    '"India":[{"score":100},{"over":50},{"wicket":7}],'+
    '"Aus":[{"score":56},{"over":47},{"wicket":3}]'+
'}'

let obj=JSON.parse(json)
document.write(obj.India[0].score)

