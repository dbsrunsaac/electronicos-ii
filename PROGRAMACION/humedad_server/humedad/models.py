from django.db import models

# Create your models here.
class Humedad(models.Model) :
    humedad_bits = models.CharField(max_length=20)
    humedad_analog = models.CharField(max_length=20)
    
    def __str__(self) :
        return self.humedad_analog
