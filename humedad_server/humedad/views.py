from django.shortcuts import render
from .models import humedad

# Create your views here.
def listar_humedad(request) :
    humedads = humedad.object.all()
    return HttpResponse(", ".join([humedad.humedad_analog for hume in humedads]))
