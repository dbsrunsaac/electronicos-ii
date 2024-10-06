from django.shortcuts import render
from django.http import HttpResponse
from .models import Humedad

# Create your views here.
def listar_humedad(request) :
    humedads = Humedad.objects.all()
    return HttpResponse(", ".join([hume.humedad_analog for hume in humedads]))
