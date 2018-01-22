let gulp = require('gulp');
let gulpif = require('gulp-if');
let exec = require('child_process').exec;
let spawn = require('child_process').spawn;


gulp.task('watch', (done) => {
	gulp.watch('./src/**/*', gulp.series('run'));
});


gulp.task('run', (done) => {
		exec("make", (err, stdout, stderr) => {
			console.log('\033c')
			if (stderr) console.log(stderr);
			done();
		});
});
