---
date: 2020-04-12
title: "Using machine-readable datasheets to create datasheets with Cyanobyte and LaTeX"
linkTitle: "Using machine-readable datasheets to create datasheets with Cyanobyte and LaTeX"
description: "Datasheets are useful reference documents that engineers are already familiar with. Could it be possible to generate PDFs just as easily as generating code?"
author: Nick Felker
---

<small>This article was cross-posted [from Medium](https://medium.com/@fleker/using-machine-readable-datasheets-to-create-datasheets-with-cyanobyte-and-latex-cf57a0e953e7)</small>

In my spare time I’ve been spending time working on [Cyanobyte](https://github.com/google/cyanobyte), a way to simplify the problem of writing peripheral drivers for different embedded platforms. You can think of the project as defining “machine-readable datasheets”.

Letting subject matter experts focus on either the peripheral specification or the embedded platform allows both to come together to develop high-quality drivers like for the [Raspberry Pi](https://github.com/google/cyanobyte/blob/a5701ce6048f69b1e3bb02a916e9991eee6e45eb/test/sampleData/raspberrypi/BMP280.py) or [Arduino](https://github.com/google/cyanobyte/blob/a5701ce6048f69b1e3bb02a916e9991eee6e45eb/test/sampleData/arduino/BMP280.cpp) without a great deal of porting code.

This approach is not just useful for code generation. It also can be used to generate [Markdown pages](https://cyanobyte.dev/docs/reference/peripheral-docs/com/cyanobyte/bmp280/) that are hosted in the developer documentation as part of the continuous delivery service.

<img src="https://miro.medium.com/max/700/1*NwWVOyKB5-YxH0DGWz6y_Q.png" /><br>
<small>https://cyanobyte.dev/docs/reference/peripheral-docs/com/cyanobyte/bmp280/ is autogenerated and hosted</small>

The success of this started getting me thinking about datasheets in general. They are useful reference documents that engineers are already familiar with. Could it be possible to generate PDFs just as easily as generating code?

Peripheral specifications are defined as YAML files with various sections that define varying levels of the peripheral: its metadata, registers, fields, and higher-level functions. In the codegen tool is loads this peripheral spec into a [Jinja2 template](https://github.com/google/cyanobyte/blob/a5701ce6048f69b1e3bb02a916e9991eee6e45eb/templates/raspberrypi.py) to output the driver.

As such, it didn’t seem at first like it was possible to do this. Existing Python libraries like [PDFKit](https://pypi.org/project/pdfkit/) seemed limited in what they could do, and it did not seem possible to create a PDF Jinja template.

Then I thought about LaTeX, a text-based format which is designed to easily export to PDF files. It would work out pretty well as I could take advantage of existing templates for datasheets. I found an [existing template on Overleaf](https://www.overleaf.com/latex/templates/electronics-datasheet-example/bppvsmthbpwg) and used that as the basis [for my own](https://github.com/google/cyanobyte/blob/a5701ce6048f69b1e3bb02a916e9991eee6e45eb/templates/datasheet.tex).

Adapting the template was not too difficult. I replaced some of the graphics with a series of tables providing reference information on each register and field. It wasn’t significantly different from a Python template.
Once I finished it, I was able to use Overleaf to render the results, and I was pretty happy with how it turned out.

<img src="https://miro.medium.com/max/627/1*HjETag6uTwBnZkyFk5XfXA.png" /><br>
<small>PDF render of [ADS1015](https://raw.githubusercontent.com/google/cyanobyte/a5701ce6048f69b1e3bb02a916e9991eee6e45eb/test/sampleData/datasheet/ADS1015.tex)</small>

The template starts with an Overview with interesting information, register descriptions, then tables. The first table is an overview of all the registers. The next section then goes into more detail about each register if it is made up of smaller fields.

<img src="https://miro.medium.com/max/629/1*Dhw1Gxj6ltzzm3K4oieqWQ.png" /><br>
<small>PDF render of [BMP280](https://raw.githubusercontent.com/google/cyanobyte/a5701ce6048f69b1e3bb02a916e9991eee6e45eb/test/sampleData/datasheet/BMP280.tex).</small>

Functions are also displayed in tables, showing the name of the function and the return type.

<img src="https://miro.medium.com/max/617/1*-ZQ1i8IjPPiYyZOS44o-lA.png" /><br>
<small>PDF render of [LSM303D](https://raw.githubusercontent.com/google/cyanobyte/a5701ce6048f69b1e3bb02a916e9991eee6e45eb/test/sampleData/datasheet/LSM303D.tex).</small>

Functions with multiple returns, in a tuple or array, are displayed as a comma-separated list.

The real power of this approach is that peripherals can be developed wholly independent of the target format. If a new peripheral is created, its generated code and datasheets will work just as well as the ones that exist now. This allows the peripheral engineers to focus on what they do best, and allow the platform integrators to do what they know best.