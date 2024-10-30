from django.shortcuts import render
from django.http import HttpResponse
from .models import Humedad

# Create your views here.
def listar_humedad(request) :
    humedads = Humedad.objects.all()
    return render(request, './humedad/humedads.html',{'humes' : humedads})
    # return HttpResponse(", ".join([hume.humedad_analog for hume in humedads]))

def listar_humedad1(request) :
    humedads = Humedad.objects.all()
    return render(request, './humedad/humedads1.html',{'humes' : humedads})
