


# plot_script.gp
set term pngcairo enhanced font 'Arial,10'
set output 'horizontal_histogram.png'

# Set data separator and define plot style
set datafile separator ';'
set style fill solid
set boxwidth 0.5   # Ajustez la largeur des barres selon vos préférences
set key off        # Désactive la légende



# Define the plot with reversed axes
plot 'temp/nombre_trajets_par_prenom_tries.txt' using 0:1:($0+1):xticlabels(2) with boxes notitle

