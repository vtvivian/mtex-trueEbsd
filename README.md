# mtex-trueEbsd
TrueEBSD is an MTEX add-on for spatial alignment and distortion correction of EBSD maps and/or images. 

Download the latest release: https://github.com/vtvivian/mtex-trueEbsd/releases

More information on the wiki page: https://github.com/vtvivian/mtex-trueEbsd/wiki

# Getting started
To start using TrueEBSD, you will need:

 - A distorted image, e.g. an EBSD map
 - A reference ground truth image, e.g. a SEM image
 - Knowledge of the distortion types between image pairs, e.g. drift (aka rolling-shutter distortion), affine, projective
 - [optional] Intermediate image(s), which may be used to separate out compound distortions into individual types.

By default, cross-correlation of the images' edge transforms are used to compute local shifts in each part of the image, which are fitted to the specified distortion model.

# Software & system requirements
- TrueEBSD (https://github.com/vtvivian/mtex-trueEbsd/releases)
- MTEX 6.1+ (https://mtex-toolbox.github.io/download)
- Ghostscript (free software for PDF export https://ghostscript.com/)
- MATLAB 2024a+
- 64-bit Windows or Linux [or Parallel Computing Toolbox]

- MATLAB toolboxes:
	- Curve Fitting Toolbox
	- Image Processing Toolbox
	- Statistics and Machine Learning Toolbox

# Contact
 - Email: vivian.tong@extern.tu-freiberg.de