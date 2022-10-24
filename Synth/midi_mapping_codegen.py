# run from Release folder

# variable extraction from mydsp.c

import re
import numpy

midi_ccs = []
param_names = []
fh_slider_names = []
min_vals = []
max_vals = []

for line in open('../Synth/mydsp.c'):
    match = re.search('"midi", "ctrl (.*?) ', line)
    if match:
        midi_ccs.append(match.group(1))
        match_fh_sliders = re.search('ui_interface->declare\(ui_interface->uiInterface, &dsp->(.*?),', line)
        if match_fh_sliders:
            fh_slider_names.append(match_fh_sliders.group(1));

    match = re.search('ui_interface->addHorizontalSlider\(ui_interface->uiInterface, \"(.*?)\"', line)
    if match:
        param_names.append(match.group(1));

    match = re.search('ui_interface->addHorizontalSlider\(ui_interface->uiInterface(.*?);', line)
    if match:
        match_min_max = re.findall('\(FAUSTFLOAT\)(.*?)f', match.group(1));
        min_vals.append(match_min_max[1])
        max_vals.append(match_min_max[2])

# order by MIDI CC

def sort_by_indexes(lst, indexes, reverse=False):
  return [lst[i] for i in indexes]

midi_ccs = [int(midi_cc) for midi_cc in midi_ccs]
s = numpy.argsort(midi_ccs)
midi_ccs = [str(midi_cc) for midi_cc in midi_ccs]
midi_ccs = sort_by_indexes(midi_ccs, s)
param_names = sort_by_indexes(param_names, s)
fh_slider_names = sort_by_indexes(fh_slider_names, s)
min_vals = sort_by_indexes(min_vals, s)
max_vals = sort_by_indexes(max_vals, s)

# code generation

f = open("../Synth/MIDI_application_CCs.c", "a")
for i,midi_cc in enumerate(midi_ccs):
    f.write('\t\t\tcase ' + midi_ccs[i] + ': //' + param_names[i] + '\n\t\t\t\tset_' + fh_slider_names[i] + "(val, " + min_vals[i] + ", " + max_vals[i] + ");\n\t\t\t\tbreak;\n")
f.close()

f = open("../Synth/soundGen_sliderSetters.c", "a")
f.write('float scale_min_max(int val, float min, float max)\n{\n\tfloat zeroToOne = ((float)val)/127;\t\n\treturn ((zeroToOne * (max-min)) + min);\n}\n\n')

for i,midi_cc in enumerate(midi_ccs):
    f.write('void set_' + fh_slider_names[i] + '(int val, float min, float max)\n{\n\tdsp->' + fh_slider_names[i] + ' = scale_min_max(val, min, max);\n}\n\n')
f.close()